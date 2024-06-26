def min_cost_to_match(finalMachineCount, machineCount, shiftingCost):
    n = len(machineCount)
    min_cost = float('inf')

    # Try all combinations of 3 regions (i, j, k) where i < j < k
    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                # Calculate the cost to match finalMachineCount[i], finalMachineCount[j], finalMachineCount[k]
                current_cost = 0
                for idx, target in zip([i, j, k], finalMachineCount):
                    current_cost += abs(target - machineCount[idx])

                # Calculate the cost to destroy extra regions (if any)
                empty_regions_cost = 0
                for idx in range(n):
                    if idx not in [i, j, k] and machineCount[idx] > 0:
                        empty_regions_cost += machineCount[idx]

                # Total cost including shiftingCost for moving all to one of the three regions
                total_cost = current_cost + empty_regions_cost + shiftingCost

                # Update minimum cost found so far
                if total_cost < min_cost:
                    min_cost = total_cost

    return min_cost