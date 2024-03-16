# I used radare2 for finding the source code of the file that I uploaded, the name of the file is `reversing the program.cpp`
# I wanna do exercises in revers engeeniring, so i did it on my program, here the step that i did:
# first I started radare2, deleting the cache
# than, I analyzed the functions, variables with the `aaa` command (if you want a more detailed analyzation you can use `aaaa` instead of `aaa`)
# than I print all the function that are include in the program, and i found the main function
# I navigated to the main function with the "s" command
# the axt command is really helpful because it search in the whole program where the current function (the main function in this case) is called from
# using the pdf or pdr function (print disassembly function) allow you to see the the assemblt code
# if you want to save the asm script in a file just type: `pdf > output.asm` and this will save in the file output.asm the code
# ps: instead of navigate with the s comand, you can use @ and the name of the function or the virtual addres, because in radare2 the @ is named like "at", so if you type pdf @main or axt@main or pdr @entry0 you can see the function without navigate to it.
# radare2 is very usefull, free and with a lot of tool, like debugging, leaving comment, see the tree program (with the V command) and so on
# here the results



$ r2 -e bin.cache=true exe  
[0x00002190]> aaa
[x] Analyze all flags starting with sym. and entry0 (aa)
[x] Analyze function calls (aac)
[x] Analyze len bytes of instructions for references (aar)
[x] Finding and parsing C++ vtables (avrr)
[x] Type matching analysis for all functions (aaft)
[x] Propagate noreturn information (aanr)
[x] Use -AA or aaaa to perform additional experimental analysis.
[0x00002190]> afl
0x00002190    1 34           entry0
0x0000286c    4 242          method.void_std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___._M_construct_char_const__char_const__char_const__std::forward_iterator_tag_
0x000021c0    4 41   -> 34   sym.deregister_tm_clones
0x000021f0    4 57   -> 51   sym.register_tm_clones
0x00002230    5 57   -> 54   sym.__do_global_dtors_aux
0x00002180    1 6            sym.imp.__cxa_finalize
0x00002270    1 9            entry.init0
0x000023e2    1 291          sym.__static_initialization_and_destruction_0__
0x000026d6    4 160  -> 134  method.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::basic_string_std.allocator_char____char_const__std::allocator_char__const_
0x0000281c    1 11           method.std::__new_allocator_char_.__new_allocator__
0x000020a0    1 6            sym.imp.__cxa_atexit
0x00002140    1 6            sym.imp.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::basic_string__
0x0000253b    1 6            loc.0000253b
0x00002541    1 11           sym._GLOBAL__sub_I__Z8usernameB5cxx11
0x00002557    1 35           method.std::char_traits_char_.lt_char_const__char_const_
0x00002776    5 132          method.bool_std::operator_char__std::char_traits_char___std.allocator_char____std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char____const__std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char____const
0x00002279    5 361          main
0x00002842    3 42           method.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___._M_construct_char_const__char_const__char_const__std::forward_iterator_tag_::_Guard::_Guard__
0x00002110    1 6            sym.imp.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::_M_dispose__
0x00002828    1 26           method.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___._M_construct_char_const__char_const__char_const__std::forward_iterator_tag_::_Guard::_Guard_std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_
0x00002960    1 9            sym._fini
0x000027fa    1 33           method.__gnu_cxx::char_traits_char_.eq_char_const__char_const_
0x0000254c    1 11           method.std.__is_constant_evaluated__
0x000026b2    1 36           method.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::_Alloc_hider._Alloc_hider__
0x0000266c    4 70           method.__gnu_cxx::char_traits_char_.length_char_const_
0x00002000    3 23           sym._init
0x0000257a   13 192          method.std::char_traits_char_.compare_char_const__char_const__unsigned_long_
0x0000263a    4 50           method.std::char_traits_char_.length_char_const_
0x00002030    1 6            sym.imp.strlen
0x00002040    1 6            sym.imp.memcmp
0x00002050    1 6            sym.imp.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::_M_set_length_unsigned_long_
0x00002060    1 6            sym.imp.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::size___const
0x00002070    1 6            sym.imp.std::__throw_logic_error_char_const_
0x00002080    1 6            sym.imp.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::_M_local_data__
0x00002090    1 6            sym.imp.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::_M_data_char_
0x000020b0    1 6            sym.imp.std::basic_ostream_char__std::char_traits_char____std::operator____std::char_traits_char____std::basic_ostream_char__std::char_traits_char_____char_const_
0x000020c0    1 6            sym.imp.std::ostream::operator___std::ostream____std::ostream__
0x000020d0    1 6            sym.imp.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::_Alloc_hider::_Alloc_hider_char__std::allocator_char__const_
0x000020e0    1 6            sym.imp.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::_M_data___const
0x000020f0    1 6            sym.imp.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::_S_copy_chars_char__char_const__char_const_
0x00002100    1 6            sym.imp.exit
0x00002120    1 6            sym.imp.std::basic_istream_char__std::char_traits_char____std::operator___char__std::char_traits_char___std::allocator_char____std::basic_istream_char__std::char_traits_char_____std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char____
0x00002130    1 6            sym.imp.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::data___const
0x00002150    1 6            sym.imp._Unwind_Resume
0x00002160    1 6            sym.imp.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::_M_create_unsigned_long__unsigned_long_
0x00002170    1 6            sym.imp.std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char___::_M_capacity_unsigned_long_
[0x00002190]> s main
[0x00002279]> axt
entry0 0x21a4 [DATA] lea rdi, [main]
[0x00002279]> iz
[Strings]
nth paddr      vaddr      len size section type  string
―――――――――――――――――――――――――――――――――――――――――――――――――――――――
0   0x00003008 0x00003008 19  20   .rodata ascii Write an username: 
1   0x00003020 0x00003020 49  50   .rodata ascii The username is correct, now write the password: 
2   0x00003052 0x00003052 23  24   .rodata ascii The password is correct
3   0x0000306a 0x0000306a 22  23   .rodata ascii put ur ass out of here
4   0x00003088 0x00003088 32  33   .rodata ascii seriusly? put ur ass out of here
5   0x000030b0 0x000030b0 49  50   .rodata ascii basic_string: construction from null is not valid
6   0x000030e2 0x000030e2 6   7    .rodata ascii Thomas
7   0x000030e9 0x000030e9 7   8    .rodata ascii Turbato

[0x00002279]> pdr
  ; DATA XREF from entry0 @ 0x21a4
┌ 361: int main (int argc, char **argv, char **envp);
│ ; var int64_t var_22h @ rbp-0x22
│ ; var int64_t var_21h @ rbp-0x21
│ ; var int64_t var_20h @ rbp-0x20
│ ; var int64_t var_18h @ rbp-0x18
│ 0x00002279      55             push rbp
│ 0x0000227a      4889e5         mov rbp, rsp
│ 0x0000227d      488d05840d00.  lea rax, str.Write_an_username:_      ; 0x3008 ; "Write an username: "
│ 0x00002284      4889c6         mov rsi, rax
│ 0x00002287      488d05322e00.  lea rax, obj.std::cout                ; loc.__bss_start
│                                                                      ; 0x50c0                                                                                                                                                            
│ 0x0000228e      4889c7         mov rdi, rax
│ 0x00002291      e81afeffff     call sym std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*) ; sym.imp.std::basic_ostream_char__std::char_traits_char____std::operator____std::char_traits_char____std::basic_ostream_char__std::char_traits_char_____char_const_                                                                                                          
│ 0x00002296      488b151b2d00.  mov rdx, qword [0x00004fb8]           ; [0x4fb8:8]=0x5450 method.std::basic_ostream_char__std::char_traits_char____std::endl_char__std.char_traits_char____std::basic_ostream_char__std::char_traits_char____                                                                                                                                                                                                                                        
│ 0x0000229d      4889d6         mov rsi, rdx
│ 0x000022a0      4889c7         mov rdi, rax
│ 0x000022a3      e818feffff     call sym std::ostream::operator<<(std::ostream& (*)(std::ostream&)) ; sym.imp.std::ostream::operator___std::ostream____std::ostream__
│ 0x000022a8      488d05913000.  lea rax, obj.tried_username_abi:cxx11_ ; 0x5340
│ 0x000022af      4889c6         mov rsi, rax
│ 0x000022b2      488d05272f00.  lea rax, obj.std::cin                 ; 0x51e0
│ 0x000022b9      4889c7         mov rdi, rax
│ 0x000022bc      e85ffeffff     call sym std::basic_istream<char, std::char_traits<char> >& std::operator>><char, std::char_traits<char>, std::allocator<char> >(std::basic_istream<char, std::char_traits<char> >&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&) ; sym.imp.std::basic_istream_char__std::char_traits_char____std::operator___char__std::char_traits_char___std::allocator_char____std::basic_istream_char__std::char_traits_char_____std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char____                                                                                                                                                     
│ 0x000022c1      488d05383000.  lea rax, obj.username_abi:cxx11_      ; 0x5300
│ 0x000022c8      4889c6         mov rsi, rax
│ 0x000022cb      488d056e3000.  lea rax, obj.tried_username_abi:cxx11_ ; 0x5340
│ 0x000022d2      4889c7         mov rdi, rax
│ 0x000022d5      e89c040000     call method bool std::operator==<char, std::char_traits<char>, std::allocator<char> >(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) ; method.bool_std::operator_char__std::char_traits_char___std.allocator_char____std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char____const__std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char____const                                                                                                                                                              
│ 0x000022da      84c0           test al, al
│ 0x000022dc      0f84cb000000   je 0x23ad
| // true: 0x000023ad  false: 0x000022e2
│ 0x000022e2      488d05370d00.  lea rax, str.The_username_is_correct__now_write_the_password:_ ; 0x3020 ; "The username is correct, now write the password: "
│ 0x000022e9      4889c6         mov rsi, rax
│ 0x000022ec      488d05cd2d00.  lea rax, obj.std::cout                ; loc.__bss_start
│                                                                      ; 0x50c0                                                                                                                                                            
│ 0x000022f3      4889c7         mov rdi, rax
│ 0x000022f6      e8b5fdffff     call sym std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*) ; sym.imp.std::basic_ostream_char__std::char_traits_char____std::operator____std::char_traits_char____std::basic_ostream_char__std::char_traits_char_____char_const_                                                                                                          
│ 0x000022fb      488b15b62c00.  mov rdx, qword [0x00004fb8]           ; [0x4fb8:8]=0x5450 method.std::basic_ostream_char__std::char_traits_char____std::endl_char__std.char_traits_char____std::basic_ostream_char__std::char_traits_char____                                                                                                                                                                                                                                        
│ 0x00002302      4889d6         mov rsi, rdx
│ 0x00002305      4889c7         mov rdi, rax
│ 0x00002308      e8b3fdffff     call sym std::ostream::operator<<(std::ostream& (*)(std::ostream&)) ; sym.imp.std::ostream::operator___std::ostream____std::ostream__
│ 0x0000230d      488d054c3000.  lea rax, obj.tried_password_abi:cxx11_ ; 0x5360
│ 0x00002314      4889c6         mov rsi, rax
│ 0x00002317      488d05c22e00.  lea rax, obj.std::cin                 ; 0x51e0
│ 0x0000231e      4889c7         mov rdi, rax
│ 0x00002321      e8fafdffff     call sym std::basic_istream<char, std::char_traits<char> >& std::operator>><char, std::char_traits<char>, std::allocator<char> >(std::basic_istream<char, std::char_traits<char> >&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&) ; sym.imp.std::basic_istream_char__std::char_traits_char____std::operator___char__std::char_traits_char___std::allocator_char____std::basic_istream_char__std::char_traits_char_____std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char____                                                                                                                                                     
│ 0x00002326      488d05f32f00.  lea rax, obj.password_abi:cxx11_      ; 0x5320
│ 0x0000232d      4889c6         mov rsi, rax
│ 0x00002330      488d05293000.  lea rax, obj.tried_password_abi:cxx11_ ; 0x5360
│ 0x00002337      4889c7         mov rdi, rax
│ 0x0000233a      e837040000     call method bool std::operator==<char, std::char_traits<char>, std::allocator<char> >(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) ; method.bool_std::operator_char__std::char_traits_char___std.allocator_char____std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char____const__std::__cxx11::basic_string_char__std::char_traits_char___std::allocator_char____const                                                                                                                                                              
│ 0x0000233f      84c0           test al, al
│ 0x00002341      7435           je 0x2378
| // true: 0x00002378  false: 0x00002343
│ 0x00002343      488d05080d00.  lea rax, str.The_password_is_correct  ; 0x3052 ; "The password is correct"
│ 0x0000234a      4889c6         mov rsi, rax
│ 0x0000234d      488d056c2d00.  lea rax, obj.std::cout                ; loc.__bss_start
│                                                                      ; 0x50c0                                                                                                                                                            
│ 0x00002354      4889c7         mov rdi, rax
│ 0x00002357      e854fdffff     call sym std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*) ; sym.imp.std::basic_ostream_char__std::char_traits_char____std::operator____std::char_traits_char____std::basic_ostream_char__std::char_traits_char_____char_const_                                                                                                          
│ 0x0000235c      488b15552c00.  mov rdx, qword [0x00004fb8]           ; [0x4fb8:8]=0x5450 method.std::basic_ostream_char__std::char_traits_char____std::endl_char__std.char_traits_char____std::basic_ostream_char__std::char_traits_char____                                                                                                                                                                                                                                        
│ 0x00002363      4889d6         mov rsi, rdx
│ 0x00002366      4889c7         mov rdi, rax
│ 0x00002369      e852fdffff     call sym std::ostream::operator<<(std::ostream& (*)(std::ostream&)) ; sym.imp.std::ostream::operator___std::ostream____std::ostream__
│ 0x0000236e      bf00000000     mov edi, 0
│ 0x00002373      e888fdffff     call sym.imp.exit
| // true: 0x00002378
│ ; CODE XREF from main @ 0x2341
│ 0x00002378      488d05eb0c00.  lea rax, str.put_ur_ass_out_of_here   ; 0x306a ; "put ur ass out of here"
│ 0x0000237f      4889c6         mov rsi, rax
│ 0x00002382      488d05372d00.  lea rax, obj.std::cout                ; loc.__bss_start
│                                                                      ; 0x50c0                                                                                                                                                            
│ 0x00002389      4889c7         mov rdi, rax
│ 0x0000238c      e81ffdffff     call sym std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*) ; sym.imp.std::basic_ostream_char__std::char_traits_char____std::operator____std::char_traits_char____std::basic_ostream_char__std::char_traits_char_____char_const_                                                                                                          
│ 0x00002391      488b15202c00.  mov rdx, qword [0x00004fb8]           ; [0x4fb8:8]=0x5450 method.std::basic_ostream_char__std::char_traits_char____std::endl_char__std.char_traits_char____std::basic_ostream_char__std::char_traits_char____                                                                                                                                                                                                                                        
│ 0x00002398      4889d6         mov rsi, rdx
│ 0x0000239b      4889c7         mov rdi, rax
│ 0x0000239e      e81dfdffff     call sym std::ostream::operator<<(std::ostream& (*)(std::ostream&)) ; sym.imp.std::ostream::operator___std::ostream____std::ostream__
│ 0x000023a3      bf00000000     mov edi, 0
│ 0x000023a8      e853fdffff     call sym.imp.exit
| // true: 0x000023ad
│ ; CODE XREF from main @ 0x22dc
│ 0x000023ad      488d05d40c00.  lea rax, str.seriusly__put_ur_ass_out_of_here ; 0x3088 ; "seriusly? put ur ass out of here"
│ 0x000023b4      4889c6         mov rsi, rax
│ 0x000023b7      488d05022d00.  lea rax, obj.std::cout                ; loc.__bss_start
│                                                                      ; 0x50c0                                                                                                                                                            
│ 0x000023be      4889c7         mov rdi, rax
│ 0x000023c1      e8eafcffff     call sym std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*) ; sym.imp.std::basic_ostream_char__std::char_traits_char____std::operator____std::char_traits_char____std::basic_ostream_char__std::char_traits_char_____char_const_                                                                                                          
│ 0x000023c6      488b15eb2b00.  mov rdx, qword [0x00004fb8]           ; [0x4fb8:8]=0x5450 method.std::basic_ostream_char__std::char_traits_char____std::endl_char__std.char_traits_char____std::basic_ostream_char__std::char_traits_char____                                                                                                                                                                                                                                        
│ 0x000023cd      4889d6         mov rsi, rdx
│ 0x000023d0      4889c7         mov rdi, rax
│ 0x000023d3      e8e8fcffff     call sym std::ostream::operator<<(std::ostream& (*)(std::ostream&)) ; sym.imp.std::ostream::operator___std::ostream____std::ostream__
│ 0x000023d8      bf00000000     mov edi, 0
└ 0x000023dd      e81efdffff     call sym.imp.exit
| // true: 0x000023e2
[0x00002279]> 
