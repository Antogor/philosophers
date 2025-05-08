#!/bin/bash

PHILO_EXEC=./philo

echo "🧪 Test 1: Basic execution with 5 philosophers, no max_eat"
$PHILO_EXEC 5 800 200 200 2
sleep 2

echo -e "\n🧪 Test 2: Each philosopher eats 3 times (should exit cleanly)"
$PHILO_EXEC 5 800 200 200 3
sleep 2

echo -e "\n🧪 Test 3: One philosopher (edge case, should pick up one fork and die)"
$PHILO_EXEC 1 800 200 200
sleep 2

echo -e "\n🧪 Test 4: High philosopher count (stress test)"
$PHILO_EXEC 200 800 200 200 2
sleep 2

echo -e "\n🧪 Test 5: Short time_to_die (death should occur)"
$PHILO_EXEC 5 310 200 200
sleep 2

echo -e "\n🧪 Test 6: Invalid number of args (should return error)"
$PHILO_EXEC 5 800 200
sleep 2

echo -e "\n🧪 Test 7: time_to_eat > time_to_die (philosopher should die while eating)"
$PHILO_EXEC 5 200 300 100
sleep 2

echo -e "\n🧪 Test 8: time_to_sleep > time_to_die (should be fine as long as they eat first)"
$PHILO_EXEC 5 400 200 500
sleep 2

echo -e "\n🧪 Test 9: Zero philosophers (should exit immediately or error)"
$PHILO_EXEC 0 800 200 200
sleep 2

echo -e "\n✅ All tests finished."
