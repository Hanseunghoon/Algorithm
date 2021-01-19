function solution(name){
    
  const arr = [0];

  const answer = [...name].reduce( (answer, s, i) => {
  
      // 문자열 name의 문자가 A이면서, 그 전 문자가 A가 아닌 경우
      // 즉, 처음으로 등장하는 A라면
      if(s === "A"){
          
          // 임시 배열 arr에 name의 i번째부터 계산하는 continuous 함수 사용
          // 연속된 A의 개수에서 A가 처음으로 등장하는 부분의 인덱스를 차 연산
          if(name[i-1] != "A")
              arr.push(continuous(name.substring(i)) - (i - 1));
          
          // 한 문자를 연산 후 우측 이동으로 인한 + 1
          return answer + 1;
          
      }
      
      // 현재 총 합수 + 알파벳 변환(좌우 이동한 수) +우측 이동한 수 
      return answer + calc_diff(name, i) + 1;
  }, 0);
  
  return answer - Math.max(...arr) - 1;
}

function calc_diff(name, i){
  // charCodeAt을 사용하여 '문자'를 정수로 아스키코드 번호로 변환 
  let diff = name.charCodeAt(i) - 65;
      
  if(diff > 13)
      diff = 26 - diff;
  
  return diff;
}

// A가 몇번 반복 되어있는지 확인
// "AAA" -> 3
function continuous(name){
  let repeat = 0;
  
  // 문자 A가 나타나지 않을 때까지 A 개수 카운트 후 반환
  for(let i = 0; i < name.length; i++){
      if(name[i] != "A")
          break;
      repeat++;
  }
  return repeat;
}