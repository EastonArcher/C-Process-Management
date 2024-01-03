#!/bin/bash

echo "Testing parent-children process program..."
for numChildren in 2 4 8; do
    echo "Number of Children: $numChildren"
    ./parent_children $numChildren
    echo
done

echo "Testing process chain program..."
for depth in 2 4 8; do
    echo "Depth: $depth"
    ./process_chain $depth
    echo
done
