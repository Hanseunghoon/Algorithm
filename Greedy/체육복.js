function solution(n, lost, reserve) {
  var answer = 0;
  
  // lost와 reserve 둘다 있는 번호를 제거
  let realLost = lost.filter(x => !reserve.includes(x));
  let realReserve = reserve.filter(x => !lost.includes(x));
 
  // 배열 lost의 학생들에게 reserve 배열의 학생들이 빌려주면 배열 lost길이가 줄어든다.
  // 총 n명에서 reserve 학생들에게 빌리지 못한 학생 수를 빼면 최대값
  answer = n - realLost.filter(a => {
      // 여벌이 있는 학생의 번호가 없는 학생의 번호의 차이가 1 이하인 학생을 찾는다.
      let b = realReserve.find(r => Math.abs(r-a) <= 1);
      
      // 만약 없으면 true를 반환하여 종료
      if(!b) 
          return true;
      
      // 찾은 학생의 번호를 지운다.
      realReserve = realReserve.filter(r => r !== b);
  }).length;
 
  return answer;
}

// function solution(n, lost, reserve) {
//   var answer = 0;
//   let arr = new Array(n);
  
//   for (let i = 0; i < n; i++)
//       arr[i] = 1;
  
//   for (let i = 0; i < lost.length; i++)
//       arr[lost[i]-1]--;

//   for (let i = 0; i < reserve.length; i++)
//       arr[reserve[i]-1]++;
  
//   for (let i = 0; i < n; i++){
//       if(arr[i] === 2 && arr[i+1] === 0){
//           arr[i+1] = 1;
//           arr[i] = 1;
//       }
//       if(arr[i] === 0 && arr[i+1] === 2){
//           arr[i+1] = 1;
//           arr[i] = 1;
//       }
//   }
  
//   for (let i = 0; i < n; i++){
//       if(arr[i] >= 1)
//           answer++;
//   }
  
//   return answer;
// }