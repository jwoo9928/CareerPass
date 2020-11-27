var slideIndex = 1;
showSlides(slideIndex);

function plusSlides(n) {
  showSlides(slideIndex += n);
}

function currentSlide(n) {
  showSlides(slideIndex = n);
}

function showSlides(n) { //전시회 작품 이동 함수
  var i;
  var slides = document.getElementsByClassName("mySlides");
  var dots = document.getElementsByClassName("dot");
  if (n > slides.length) {slideIndex = 1}    
  if (n < 1) {slideIndex = slides.length}
  for (i = 0; i < slides.length; i++) {
      slides[i].style.display = "none";  
  }
  for (i = 0; i < dots.length; i++) {
      dots[i].className = dots[i].className.replace(" active", "");
  }
  slides[slideIndex-1].style.display = "block";  
  dots[slideIndex-1].className += " active";
}

function slideExplain() { //전시회 작품 제목 및 설명 추가 함수

}

function main_exhibition() { //메인 화면의 전시회 종류 추가 버튼

}

function move_main() { //메인화면으로 이동하는 함수
    location.href="./main.html";
}

function move_login() { //로그인 화면으로 이동하는 함수
    location.href="./login.html";
}
function move_info() { //개인정보 화면으로 이동하는 함수
    location.href="./info.html";
}

function signin_check() { //회원가입 폼의 필수요소를 전부 입력했는지 확인하는 함수
    
}

function author_window() { //작가 개인정보 추가 화면

}

function signout_window() { //탈퇴 확인 레이어 팝업
    var pop = document.getElementById("signout_window");
    pop.style.display = "block";
    pop.style.top= "100px";
    pop.style.left = "100px";
}

function signout_cancle() { //탈퇴 확인 레이어 close
    var pop = document.getElementById("signout_window");
    pop.style.display = "none";
}

function view_exhibition() {//종류별 전시회 감상

}

function img_add() {//전시회 이미지 추가
    var src = $("#image").val().split("\\")[2];
    if(src!=null) {
        $("#checkimg").append('<img src="./'+src+'">');
    }
}

function next_add() { //다음 작품 등록

}

function create_exhibition() { //전시회 생성

}

function show_athor() { //작가 프로필 화면에서 보여줄 데이터를 정리하고 보여주는 함수

}

function authorExhibition() {//작가의 전체작품을 볼수 이쓴ㄴ 페이지로 이동
    location.href="./author_exhibition.html";
}
