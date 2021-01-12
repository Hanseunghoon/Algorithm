function solution(numbers, target) {
  var answer = 0;
  recur(0, 0);
  return answer;

  // 재귀함수 형태의 DFS 구현
  function recur(cnt, sum){
      
      // numbers의 모든 수를 연산하고, target과 같은 합이 나오면 answer증가
      if(cnt === numbers.length){
          if(sum === target)
              answer++;
          return
      }

      // + , - 연산 모두 수행
      recur(cnt+1, sum+numbers[cnt]);
      recur(cnt+1, sum-numbers[cnt]);
  }
}