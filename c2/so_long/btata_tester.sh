#!/bin/bash

# Create test directory
make
mkdir -p test_maps
mv so_long test_maps
make fclean
cd test_maps
./run_tests.sh

# Valid Maps
echo -n "1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111" > valid_basic.ber

echo -n "1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111" > valid_large.ber

echo -n "111
1P1
1E1
1C1
111" > valid_minimal.ber

# Invalid Character Maps
echo -n "1111111111111
10010000000C1
1000011111001
1P0011X000001
1111111111111" > invalid_char.ber

# Missing Components Maps
echo -n "1111111111111
10010000000C1
1000011111001
100011E000001
1111111111111" > missing_player.ber

echo -n "1111111111111
10010000000C1
1000011111001
1P0011000001
1111111111111" > missing_exit.ber

echo -n "1111111111111
1001000000001
1000011111001
1P0011E000001
1111111111111" > missing_collectible.ber

# Duplicate Components Maps
echo -n "1111111111111
10010P00000C1
1000011111001
1P0011E000001
1111111111111" > duplicate_player.ber

echo -n "1111111111111
10010E00000C1
1000011111001
1P0011E000001
1111111111111" > duplicate_exit.ber

# Wall Issues Maps
echo -n "0111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111" > broken_wall.ber

echo -n "1111111111111
10010000000C0
1000011111001
1P0011E000001
1111111111111" > broken_wall_side.ber

# Non-rectangular Maps
echo -n "1111111111111
100100000C1
1000011111001
1P0011E000001
1111111111111" > non_rectangular.ber

# Path Issues Maps
echo -n "1111111111111
10010000000C1
1111111111111
1P0011E000001
1111111111111" > no_valid_path.ber

echo -n "1111111111111
1001000000011
11111111110C1
1P0011E000001
1111111111111" > unreachable_collectible.ber

# Empty/Invalid Files
touch empty.ber
echo -n "not a map" > invalid_content.ber
echo -n "" > blank.ber

# Wrong Extension Files
echo -n "1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111" > wrong_extension.txt

# Test Script
echo '#!/bin/bash
RED="\033[0;31m"
GREEN="\033[0;32m"
NC="\033[0m"

test_map() {
    echo -n "Testing $1: "
    ./so_long "$1" > /dev/null 2>&1
    if [ $? -eq $2 ]; then
        echo -e "${GREEN}PASS${NC}"
    else
        echo -e "${RED}FAIL${NC}"
    fi
}

# Valid maps should return 0
echo "Testing Valid Maps:"
test_map "valid_basic.ber" 0
test_map "valid_large.ber" 0
test_map "valid_minimal.ber" 0

# Invalid maps should return 1
echo -e "\nTesting Invalid Maps:"
test_map "invalid_char.ber" 1
test_map "missing_player.ber" 1
test_map "missing_exit.ber" 1
test_map "missing_collectible.ber" 1
test_map "duplicate_player.ber" 1
test_map "duplicate_exit.ber" 1
test_map "broken_wall.ber" 1
test_map "broken_wall_side.ber" 1
test_map "non_rectangular.ber" 1
test_map "no_valid_path.ber" 1
test_map "unreachable_collectible.ber" 1
test_map "empty.ber" 1
test_map "invalid_content.ber" 1
test_map "blank.ber" 1
test_map "wrong_extension.txt" 1
test_map "nonexistent.ber" 1

# Delete executable
rm so_long' > run_tests.sh

chmod +x run_tests.sh
