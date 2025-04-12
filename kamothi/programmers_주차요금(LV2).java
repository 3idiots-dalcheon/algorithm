import java.util.*;
// 기본요금 + 단위시간(10분) 요금
// 누적 주차시간이 기본 시간 이하라면 기본 요금만 부과한다.
// 어떤 차량이 입차된 후에 출차된 내역이 없다면, 23:59에 출차된 것으로 간주
// 초과한 시간이 단위 시간으로 나누어 떨어지지 않으면, 올림
class Solution {
    Map<String,Integer> tmp = new HashMap<>();
    Map<String,Integer> result = new HashMap<>();
    public int[] solution(int[] fees, String[] records) {
        
        for(String input : records){
            String[] tmp1 = input.split(" ");
            String[] tmp2 = tmp1[0].split(":");
            int hour = Integer.parseInt(tmp2[0]);
            int minute = hour*60 + Integer.parseInt(tmp2[1]);
            
            
            String number = tmp1[1];
            String inout = tmp1[2];
            
            if("IN".equals(inout)){
                tmp.put(number,minute);
            }
            else{
                int time = minute - tmp.get(number);
                result.put(number,result.getOrDefault(number,0) + time);
                tmp.remove(number);
            }
        }
        if(!tmp.isEmpty()){
            for(String key : tmp.keySet()){
                int minute = 24*60-1;
                int time = minute - tmp.get(key);
                result.put(key,result.getOrDefault(key,0) + time);
            }
        }
        
        List<String> list = new ArrayList<>(result.keySet());
        Collections.sort(list);
        
        List<Integer> answer = new ArrayList<>();
        
        for(String key : list){
            int sum = 0;
            if(result.get(key) < fees[0]){
                sum = fees[1];
            }else{
                sum = fees[1] + (int)Math.ceil((result.get(key) - fees[0]) / (double)fees[2])*fees[3];
            }
            
            answer.add(sum);
        }
        
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}
