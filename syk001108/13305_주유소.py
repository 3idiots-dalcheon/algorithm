def minimum_cost_to_travel():
    import sys
    input = sys.stdin.read
    data = list(map(int, input().split()))

    N = data[0] # 도시 개수
    road_lengths = data[1:N] # 도로 길이
    fuel_prices = data[N:] # 기름 리터당 가격

    # 최소 비용 계산
    min_cost = 0
    min_price = fuel_prices[0]

    for i in range(N - 1):
        min_cost += min_price * road_lengths[i]
        min_price = min(min_price, fuel_prices[i + 1])

    print(min_cost)

minimum_cost_to_travel()
