



# Everything after this is code
	.text


main:
	# Main function to calculate the square of a number
	#     int x, y;
	# x is in $t0
	# y is in $t1

	# TODO: This program
	li	$v0, 	4	# Print a string
	la	$a0, 	input_str
	syscall

	#     printf("Enter a number: ");
	la	$a0, 	input_str
	li	$v0, 	4
	syscall		# Syscall 4 - Print a string

	#     scanf("%d", &x);
	li	$v0, 	5
	syscall 	# Syscall 5 - read integer - stores into v0
	move	$t0, 	$v0

	#     y = x * x;
	mul	$t1, 	$t0,	$t0

	#     printf("%d", y);
	move	$a0, 	$t1
	li	$v0, 	1
	syscall		# Syscall 1 - Print a number

	#     printf("\n");
	li	$a0, 	'\n'
	li	$v0, 	11
	syscall		# Syscall 11 - Print a character

					# return 0;
	li	$v0,	0		# $v0 = 0
	jr	$ra			# jump to $ra
	

	.data
input_str: .asciiz "Enter a number: "
