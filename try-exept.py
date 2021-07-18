firstNumber = input('Enter first number: ')
secondNumber = input('Enter second number: ')

try:
    print('The answer is: ', int(firstNumber)+int(secondNumber))
except ValueError:
    print('I was ask u about numbers...')
