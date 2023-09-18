# Prints a right - angled triangle of asterisks, 10 rows high.

	.text

main:
	# Main function to print a triangle of asterisks
	# counter i is in ...
	# counter j is in ...

	# TODO: Add the missing loops in this program

					# printf("*");
	li	$a0, 	'*'
	li	$v0,	11		# syscall no. 11
	syscall

					# j++;
	addi	$t1, 	$t1, 	1
					# goto main__col_loop_cond;
					# printf("\n");
	li	$a0,	'\n'
	li	$v0,	11		# syscall no. 11
	syscall

epilogue:
	li 	$v0, 	0		# return 0;
	jr	$ra


	.data 
	# Nothing here!