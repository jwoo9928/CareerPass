<?php
header("Content-Type: application/json");

$date = $_POST["date"];
$time = $_POST["time"];
$title = $_POST["title"];
$description = $_POST["description"];
$id = $_POST["id"];
$action = $_POST["action"];

$dateSplit = explode("-", $date);
$timeSplit = explode(":",$time);
$fileName = $id."_".(string)$dateSplit[0].(string)$dateSplit[1].".json";

if($action == "Save") {
    if(!file_exists($fileName))  {
        $array = array();
        array_push($array,array("date" => $date, "time" => $time, "title" => $title, "discription" => $description));
    } else {
        $array = json_decode(file_get_contents($fileName),true);
        for($i = 0;$i<count($array);$i++) {
            if($array[$i]["time"] == $time){
                alert($array);
                exit();
            }
        }
        array_push($array,array("date" => $date, "time" => $time, "title" => $title, "discription" => $description));
    }
    echo "저장되었습니다.";
    file_put_contents($fileName, json_encode($array));

} else if($action == "Update") {

} else if($action == "Submint") {

}

?>