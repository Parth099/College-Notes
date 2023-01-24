MAX_POP = 39740
TUITION = 9972

days = input("Input days or enter 'exit': ")

if days.lower() == 'exit':
    exit()

try:
    days = int(days)
except ValueError:
    print("Invalid day value.")
    exit()

rate = 1.2
initial_infection = 7 # D0
infections = [initial_infection]

for i in range(days):

    if infections[i] >= MAX_POP:
        break

    infections.append((rate * infections[i]) // 1)

total_drops = sum(infections[0:min(14, len(infections))])


print("Temple Total loss: ", total_drops * TUITION)
print("total infections: ", sum(infections))