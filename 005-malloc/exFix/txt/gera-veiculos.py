import random

# Gerar dados aleatórios para 150 veículos
def gerar_veiculos(num_veiculos=150):
    placas = []
    modelos = ["Modelo" + str(i) for i in range(1, num_veiculos + 1)]
    marcas = ["Marca" + chr(65 + i % 26) for i in range(num_veiculos)]
    quilometragens = [random.randint(5000, 200000) for _ in range(num_veiculos)]
    
    for i in range(num_veiculos):
        placa = ''.join(random.choices('ABCDEFGHIJKLMNOPQRSTUVWXYZ', k=3)) + ''.join(random.choices('0123456789', k=4))
        placas.append(placa)
    
    veiculos = []
    for i in range(num_veiculos):
        veiculos.append(placas[i])
        veiculos.append(modelos[i])
        veiculos.append(marcas[i])
        veiculos.append(str(quilometragens[i]))
    
    return veiculos

# Gerar o conteúdo do arquivo
veiculos = gerar_veiculos()
conteudo_arquivo = '\n'.join(veiculos)

# Salvar no arquivo bdveiculos.txt
with open('./005-malloc/exFix/txt/bdveiculos.txt', 'w') as arquivo:
    arquivo.write(conteudo_arquivo)

