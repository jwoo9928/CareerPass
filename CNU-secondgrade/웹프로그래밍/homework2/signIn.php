<?php
header("Content-Type: application/json");
$id = "";
$pw = "";

$id = $_POST['text'];
$pw= $_POST['pw'];
$json = json_encode(array("id" => $id, "pw" => $pw));
echo($json);
if(!file_exists("person.json")) {
    $array = array();
    array_push($array,array("id" => $id, "pw" => $pw));
}
else {
    $array = json_decode(file_get_contents("person.json"),true);
    idCheck($array, $id, $pw);
    array_push($array,array("id" => $id, "pw" => $pw));
}
file_put_contents("person.json", json_encode($array));

function idCheck($array, $id, $pw) {
    for($i = 0;$i<count($array);$i++) {
        if(array_search($id,$array[$i])){
            if($array[$i]["id"] == $id) {
                alert("이미 존재하는 아이디 입니다.");
                exit(0);
            }
        }
    }
}
?>