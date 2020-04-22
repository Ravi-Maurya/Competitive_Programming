def solution(N, S, T):
    ships = S.split(',')
    ships_all = []
    alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                'V', 'W', 'S', 'Y', 'Z']

    # Find all the points of the ships on the map.
    for ship in ships:
        ship_pos = []
        ship_start = ship.split()[0]
        ship_stop = ship.split()[1]
        # Horizontal ship, same numbers
        if ship_start[0:-1] == ship_stop[0:-1]:
            for i in range(alphabet.index(ship_start[-1]), alphabet.index(ship_stop[-1]) + 1):
                ship_pos.append(ship_start[0:-1] + alphabet[i])
        # Vertical ship, same letters
        elif ship_start[-1] == ship_stop[-1]:
            for num in range(int(ship_start[0:-1]), int(ship_stop[0:-1]) + 1):
                ship_pos.append(str(num) + ship_start[-1])
        # Square ship
        else:
            ship_pos.append(ship_start)
            ship_pos.append(ship_start[0:-1] + alphabet[alphabet.index(ship_start[-1]) + 1])
            ship_pos.append(str(int(ship_start[0:-1]) + 1) + ship_start[-1])
            ship_pos.append(ship_stop)

        ships_all.append(ship_pos)

    # Find the hits.
    ships_hit = 0
    ships_sunk = 0
    shots = T.split()
    for ship in ships_all:
        hit = 0
        for shot in shots:
            for ship_point in ship:
                if ship_point == shot:
                    hit = hit + 1
                    break
        if hit == len(ship):
            ships_sunk = ships_sunk + 1
        elif hit > 0:
            ships_hit = ships_hit + 1

    return ships_sunk, ships_hit


result_1 = solution(4, '1B 2C,2D 4D', '2B 2D 3D 4D 4A')     # '1,1'
result_2 = solution(3, '1A 1B,2C 2C', '1B')     # '0,1'
result_3 = solution(12, '1A 2A,12A 12A', '12A')     # '1,0'

print(result_1, result_2, result_3)