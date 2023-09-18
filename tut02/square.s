

# Everything after this is code
	.text

main:
	# Main function to calculate the square of a number
	# x is in $t0
	# y is in $t1

	# TODO: This program

				# printf("Enter a number: ");
	la	$a0, 	input_str
	li	$v0, 	4 	# syscall 4 - print string
	syscall

		# scanf("%d", &x);
	li	$v0, 	5	# syscall 5 - read int
	syscall
	move	$t0, 	$v0	# scanf("%d")

		# y = x * x;
	mul	$t1,	$t0,	$t0

		# printf("%d", y);
	li	$v0, 	1	# syscall 1 - print int
	move	$a0, 	$t1
	syscall

		# printf("\n");
	li	$a0,	'\n'
	li	$v0, 	11
	syscall

					# return 0;
	li	$v0,	0		# $v0 = 0
	jr	$ra			# jump to $ra
	

	.data
input_str: .asciiz "Enter a number: "
