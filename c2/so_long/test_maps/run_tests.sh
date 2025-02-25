#!/bin/bash
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
rm so_long
