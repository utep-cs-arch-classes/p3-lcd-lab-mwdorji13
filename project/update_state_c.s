	.arch msp430g2553
	.p2align 1,0
	.text

	.global update_state
	.extern state

jmp_table:     .word case_0
	       .word case_1
	       .word case_2
               .word case_3

	mov &state, r12
	add r12, r12
	mov jmp_table(r12), pc

case_0:
	call #but1
	jmp end_switch

case_1:
	call #but2
	jmp end_switch

case_2:
	call #but3
	jmp end_switch

case_3:
	call #but4
	jmp end_switch

end_switch:
	pop r0
	



	
	add #1, &count

	cmp &flip, &count

	jc end_if

	sub.b #1, &green_on

	sub.b #1, &red_on

	mov.b #1, &led_changed

	call led_update

	mov #0, &count

	pop r0



end_if:

	pop r0
