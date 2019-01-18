def largest_product(series, size):
    if len(series) - size < 0 or size < 0:
        raise ValueError("Size not correct")
    elif len(series) > 100:
        pass
    else:
        max = 0
        for l in range(len(series) - size + 1):
            product = 1
            for i in range(size):
                product *= int(series[l + i])

            if max < product:
                max = product

    return max