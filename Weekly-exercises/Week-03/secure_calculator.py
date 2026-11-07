import operator as op
import ast

allowed_operations = {
    'pow': pow,
    '+': op.__add__,
    '-': op.__sub__,
    '*': op.__mul__,
    '/': op.__truediv__,
    '**': op.__pow__,
}

command = input('Digite aqui a operação: ')

try:
    parsed = ast.parse(command, mode='eval')
    for node in ast.walk(parsed):
        if not isinstance(node, (ast.Module, ast.Expr, ast.BinOp, ast.Num)):
            raise ValueError('Expressão inválida.')
        if isinstance(node, ast.BinOp) and not isinstance(node.op, (ast.Add, ast.Sub, ast.Mult, ast.Div, ast.Pow)):
            raise ValueError('Operação não permitida:', node.op)
    result = eval(compile(parsed, filename='<ast>', mode='eval'), allowed_operations)
    print(result) 
except Exception as e:
    print('Erro:', str(e))
