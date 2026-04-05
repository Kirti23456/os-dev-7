[bits 32]
extern keyboard_handler_main
global keyboard_handler_stub

keyboard_handler_stub: ;
    pushad ;
    call keyboard_handler_main ;
    popad ;
    iretd ;
