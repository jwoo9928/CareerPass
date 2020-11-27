<?php
    $id = $_POST["id"];
    $pw = $_POST["pw"];
    $action = $_POST["action"];
    if($action == "로그인") {
        if(!preg_match("^([A-Za-z0-9]){6,15}",$id)) {
            echo("test1");
        }
        if(!preg_match("^.*(?=^.{8,15}$)(?=.*\d)(?=.*[a-zA-Z])(?=.*[!@#$%^&+=]).*",$pw)) {
            echo("Test2");
        }

    }else {

    }
    
?>