
//로그인 폼 나타내기
$("#join").click(function(){
    var pop = $("#login");
    pop.css("display","block");
    pop.css("top","70px");
    pop.css("left","70px");
});

//로그인 폼 입력 조건 처리 및 POST 전송

function LoginOrSignin(value) {
    inputCheck($("#text").val(), $("#pw").val(), value);
}

//입력 조건 체크 함수
function inputCheck(v1,v2, val) {
    var id_reg = /^([A-Za-z0-9]){6,15}$/gi;
    var pw_reg = /^.*(?=^.{8,15}$)(?=.*\d)(?=.*[a-zA-Z])(?=.*[!@#$%^&+=]).*$/gi;

    if(!id_reg.test(v1) || !pw_reg.test(v2)){
        alert("아이디 또는 패스워드가 입력 양식에 맞지 않습니다.");
        $("#text").val("");
        $("#pw").val("");
    }
    else {
        if(val == "SignIn") {
            createData();
            AjaxCall();
            alert("회원 가입이 완료되었습니다.");
        }
        else {
            alert("not Yet");
        }
        $("#login").css("display","none");
    }
}

//데이터 생성 함수
function createData() {
    var sendData = {id:$('#text').val(), pw:$('#pw').val()};
    return sendData;
}

//데이터 전송 함수
function AjaxCall() {
    $.ajax({
        type: "POST",
        url : "./signIn.php?mode=POST",
        data: createData(),
        dataType:"json",
        success : function(data) {
            alert(JSON.stringify(data));
            alert("finish.");
        },
        error:function(jqXHR, textStatus, errorThrown) {
            console.log(jqXHR.responseText);
        }
    });
}
