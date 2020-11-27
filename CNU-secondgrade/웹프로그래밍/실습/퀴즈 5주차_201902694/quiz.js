var bt = document.getElementById('add');
bt.addEventListener('click', function(event){
  var lists = document.createElement('li');
  var result = document.getElementById("value").value;
  var text = document.createTextNode(result);
  lists.appendChild( text );
  lists.id=result;
  document.getElementById('list').appendChild( lists );
});


var rm = document.getElementById('list');
rm.addEventListener('click', function(event) {
  var name = event.target.id;
  var reg = /[^1-2]/gi;
  var elem = document.getElementById(name);
  var inputNumber = prompt("삭제는 1, 수정은 2를 입력하세요","");
  if(inputNumber==null) {
    alert("취소되었습니다.")
  }else {
    if(inputNumber=="") {alert("번호를 입력하지 않으셨습니다.");}
    else if(reg.test(inputNumber)) { alert("번호를 잘못 입력하셨습니다");}
    else if(inputNumber==1){
      var elem = document.getElementById(name);
      elem.parentNode.removeChild(elem);
    }
    else {
      var mod = prompt("추가할 글을 입력하세요","");
      document.getElementById(name).innerText = mod;
    }
  }
});
