.data
input_str: .asciiz "Enter a number: "
too_big_str: .asciiz "square too big for 32 bits\n"

# Everything after this is code
.text

main:
	# Main function to calculate the square of a number
	# x is in $t0
	# y is in $t1
	# 46340 is in $t2

					# printf("Enter a number: ");
	la	$a0,	input_str	# 
	li	$v0,	4		# syscall no. 4 
	syscall
	
					# scanf("%d", &x);
	li	$v0,	5		# syscall no. 5 
	syscall
	move 	$t0,	$v0		# $t0 = $v0

	# TODO: Add a check here to see if the number is too big
	# to be squared. If it is, print the error message and return
	# without doing any calculations.
	
	li 	$t2, 	46340

	# Add a print statement here...
	li	$t2, 	46340
	# if (x <= SQUARE_MAX)
        # goto square_if_ok;
	ble	$t0, 	$t2, 	square_if_ok

square_if_too_big:
	# printf("square too big for 32 bits\n");
	la	$a0,	too_big_str	# 
	li	$v0,	4		# syscall no. 4 
	syscall
	#     goto main__end;
	b	main__end

	#     if (x <= SQUARE_MAX)
	#         goto if_x_lt_46340;
	ble	$t0,	$t2,	if_x_lt_46340
	# gotos turn into branch statements

	#     printf("square too big for 32 bits\n");
	la	$a0,	too_big_str	#
	li	$v0,	4		# syscall no. 4
	syscall

	#     goto if_x_lt_46340_end;
	b	if_x_lt_46340_end

if_x_lt_46340:


	mul	$t1,	$t0,	$t0	# y = x * x;

					# printf("%d", y);
	move 	$a0,	$t1		# $a0 = $t1
	li	$v0,	1		# syscall no. 1 
	syscall

					# printf("\n");
	li	$a0,	'\n'
	li	$v0,	11		# syscall no. 11
	syscall

if_x_lt_46340_end:

main__end:
					# return 0;
	li	$v0,	0		# $v0 = 0
	jr	$ra			# jump to $ra
