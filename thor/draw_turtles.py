import turtle
import re
import sys


def error() -> None:
	print('Please provide a valid path to the turtle instructions file', file=sys.stderr)
	print('Usage: python3 draw_turtles.py [filename]', file=sys.stderr)
	exit(1)


def let_turtle_draw(lines: list[str]) -> None:
	barry = turtle.Turtle()

	x = 0
	barry.goto(x, 0)
	barry.setheading(90)
	barry.speed(10)

	for line in lines:
		if not line:
			x += 100
			barry.penup()
			barry.setheading(90)
			barry.goto(x, 0)
			barry.pendown()

		ints = list(map(int, re.findall(r'\d+', line)))
		if 'gauche' in line:
			barry.left(ints[0])
		elif 'droite' in line:
			barry.right(ints[0])
		elif 'Avance' in line:
			barry.forward(ints[0])
		elif 'Recule' in line:
			barry.back(ints[0])

	input('Press enter when you\'re done, thanks.')


if __name__ == '__main__':
	if len(sys.argv) != 2:
		error()
	try:
		with open('turtle.txt') as f:
			instructions = f.read().splitlines()
	except FileNotFoundError:
		error()
	let_turtle_draw(instructions)