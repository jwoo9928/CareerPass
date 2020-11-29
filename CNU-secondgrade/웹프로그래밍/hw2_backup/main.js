
//로그인 폼 나타내기
$("#join").click(function(){
    var pop = $("#login");
    pop.css("display","block");
    pop.css("top","70px");
    pop.css("left","600px");
});

//로그인 폼 입력 조건 처리 및 POST 전송
function LoginOrSignin(value) {
    inputCheck($("#text").val(), $("#pw").val(), value);
}

$('.submit').click(function() {
   alert($('.submit').val());
});

//입력 조건 체크 함수
function inputCheck(v1,v2, val) {
    var id_reg = /^([A-Za-z0-9]){6,15}$/gi;
    var pw_reg = /^.*(?=^.{8,15}$)(?=.*\d)(?=.*[a-zA-Z])(?=.*[!@#$%^&+=]).*$/gi;
    AjaxCall(val);
}

//데이터 생성 및 데이터 전송 함수
function AjaxCall(val) {
    var sendData = {id:$('#text').val(), pw:$('#pw').val(), action:val};
    $.ajax({
        type: "POST",
        url : "./signIn.php?mode=POST",
        data: sendData,
        dataType:"text",
        success : function(data) {
            if(data == $('#text').val()){
                loginSuccess(data);
            }
            else {alert(data);}
        }
    });
}

//로그인 성공시 이번주 달력 상단의 년도와 월, 달력에 날짜를 추가하고 변경하는 함수
function loginSuccess(data) {
    $("#success").append(data);
    var today = new Date();
    today = new Date(today.getFullYear(), today.getMonth(), today.getDate());
    $("#today").append(String(today.getFullYear())+"년 "+String(today.getMonth()+1)+"월");
    $("#today").css("text-align","center");
    var days = $(".title").children();
    var index = today.getDay();
    for(var i=index;i>=0;i--) {
        days.eq(index-i).prepend("<span>"+(today.getDate()-i)+"</span>");
        days.eq(index-i).children().css("color","red");
    }
    for(var i=1;i<7-index;i++) {
        var count = today.getDate();
        if(count >= 30) { count = 0};
        days.eq(index+i).prepend("<span>"+(count+i)+"</span>");
        days.eq(index+i).children().css("color","red");
    }
    showToDo();
    $("#login").css("display","none");
    $("#Add").attr("disabled",false);
}


//todo add 폼 나타내기
$("#Add").click(function(){
    var pop = $("#todo");
    pop.css("display","block");
    pop.css("top","20px");
    pop.css("left","70px");
});

//todo cancle 버튼 기능 함수
$("#Cancel").click(function() {
    $("#todo").css("display","none");
});

// todo 폼 데이터 가져와서 생성 및 todo 저장 함수
function saveAjaxCall(val) {
    var sendData = {date:$("#date").val(),
    time:$("#time").val(), title:$("#title").val(),
    description:$("#description").val(), id:$("#success").text(), action:val};

    $.ajax({
        type: "POST",
        url : "./saveToDo.php?mode=POST",
        data: sendData,
        dataType:"text",
        success : function(data) {
           alert(data);
           showToDo();
        }
    });
}

/*확인된 todo list를 화면에 나타내는 힘수*/
function showToDo() {
    var Data = {id:$("#success").text(),date:$("#today").text()};
    var todoData;
    $.ajax({
        type: "POST",
        url : "./checkToDo.php?mode=POST",
        data: Data,
        dataType:"json",
        success : function(data) {
            createToDo(data);
        },
        error : function()  {
            alert("등록된 일정이 없습니다.");
        }
    });
    
}

//todo list box를 생성하는 함수
function createToDo(data) {
    var table = $(".data").children();
    var day = $(".title").children();
    for(var j=0;j<7;j++) {table.eq(j).empty();}
    for(var i=0;i<data.length;i++) {
        var index = parseInt(data[i]["date"].split("-")[2]);
        for(var j=0;j<7;j++) {
            if(day.eq(j).children().eq(0).text() == index) {
                table.eq(j).append("<div class='todobox'>"+data[i]["title"]+"</div>");
            }
        }

    }
}