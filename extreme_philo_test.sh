#!/bin/bash

# Lanzar con:
	# valgrind --leak-check=full ./philo 4 800 200 200
	# timeout 5s ./philo 100 200 100 100

# CASOS DONDE NO MUERE NADIE
echo "🧪 Test 1: CASOS DONDE NO MUERE NADIE"
	# Básico, estable
./philo 5 800 200 200
	# Más ajustado pero aún viable
./philo 4 410 200 200
	# Con número de comidas (todos paran al llegar)
./philo 3 800 200 200 5

# CASOS DONDE MUEREN FILÓSOFOS
echo "🧪 Test 2: CASOS DONDE MUEREN FILÓSOFOS"
	# Comer y dormir duran más que el tiempo de vida
./philo 4 100 200 200
	# Solo uno puede comer a la vez y hay congestión
./philo 3 150 100 100
	# CORREGIR-1 filósofo solo: inevitable muerte (no puede tomar dos forks)
./philo 1 300 100 100

# CASOS EXTREMOS
echo "🧪 Test 3: CASOS EXTREMOS"
	# Muchos filósofos, tiempo justo
./philo 100 300 100 100
	# Tiempo para comer mayor que el de morir (debe morir)
./philo 5 150 300 100
	# Tiempo para dormir mayor que el de morir (debe morir si no come antes)
./philo 5 150 100 300
	# 0 filósofos (debe manejarse como error o terminar inmediatamente)
./philo 0 800 200 200
	# Comidas limitadas con ajuste apretado
./philo 5 210 100 100 3

# CASOS DE ERROR
echo "🧪 Test 4: CASOS DE ERROR"
	# Argumentos inválidos
./philo               # Faltan argumentos
./philo 4             # Faltan argumentos
./philo 4 -800 200 200    # Valores negativos - CORREGIR - NO FALLA
./philo 4 800 abc 200     # Argumento no numérico - CORREGIR - NO FALLA
./philo 4 800 0 200       # Comer = 0, inválido - CORREGIR - NO FALLA
