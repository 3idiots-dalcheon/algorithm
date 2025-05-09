// 그리디
function solution(people, limit) {
    people.sort((a, b) => a - b); // 몸무게 오름차순 정렬
    let left = 0; // 가장 가벼운 사람
    let right = people.length - 1; // 가장 무거운 사람
    let boats = 0;

    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            left++; // 둘 다 태울 수 있으면 가벼운 사람도 이동
        }
        // 무거운 사람은 항상 보트 탑승
        right--;
        boats++;
    }

    return boats;
}
