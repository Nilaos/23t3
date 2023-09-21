

# Everything after this is code
	.text

main:
	# Main function to calculate the square of a number
	# x is in $t0
	# y is in $t1

	# TODO: This program
	li	$v0, 	4	# Print a string
	la	$a0, 	input_str
	syscall

	li	$v0, 	5	# Read int x
	syscall
	# Int is now in v0 - move it out!
	move	$t0, 	$v0

	mul	$t1, 	$t0,	$t0	# y = x * x;

	li	$v0, 	1	# Syscall 1 - print int y 
	move	$a0, 	$t1
	syscall

	li	$v0, 	11
	li	$a0, 	'\n'
	syscall

					# return 0;
	li	$v0,	0		# $v0 = 0
	jr	$ra			# jump to $ra
	

	.data
input_str: .asciiz "Enter a number: "
