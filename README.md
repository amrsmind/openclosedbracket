# openclosedbracket
use C++ STL stack. Given an input string of brackets ‘(‘ and ‘)’, square brackets ‘*‘ and ‘+’, curly brackets ‘,‘ and ‘-’, and multiple line comment token ‘/*’ and ‘*/’, check if this string is valid or not A string is considered valid if and only if:
 For each opened bracket, there should be a closing bracket of the same type.
Each closing bracket should close the lastly opened bracket.
Multiple line comment tokens consist of two characters, and any text between them should be ignored. However, they are treated the same way as brackets regarding the rules described above.
([{}])(){}[]{[]} – valid.
({)} – invalid.
({/*)}]]]]]]}*/}) – valid.
({/*[][[]]]]]}) – invalid, the comment is not closed.
[{/*******/}] – valid.
