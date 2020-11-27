<?php
    $file = fopen("data.txt", "r");

    $arr = [];

    while(!feof($file)){
        $name = fgets($file);
        $name = preg_replace('/\r\n|\r|\n/','',$name);
        if(substr_count($name, $_GET['name']) > 0){
            $line = fgets($file);
            $line = preg_replace('/\r\n|\r|\n/','',$line);
            $lowerLine = strtolower($line);
            $have = substr_count($lowerLine, $_GET['word']);
            if($have > 0){
                array_push($arr, [$name, $line, $have]);
            }
        }else{
            fgets($file);
        }
    }

    $len = sizeof($arr);
    for($i = 0; $i < $len; $i++){
        for($j = 0; $j < $len; $j++){
            if($arr[$i][2] < $arr[$j][2]){
                $temp = $arr[$i];
                $arr[$i] = $arr[$j];
                $arr[$j] = $temp;
            }
        }
    }

    if($_POST['sort'] == "up"){
        for($i = 0; $i < $len; $i++){
            echo $arr[$i][0] . " :";
            echo $arr[$i][1] . "\n<br>";
        }
    }else{
        for($i = $len-1; $i >= 0; $i--){
            echo $arr[$i][0] . " :";
            echo $arr[$i][1] . "\n<br>";
        }
    }

    fclose($file);
?>