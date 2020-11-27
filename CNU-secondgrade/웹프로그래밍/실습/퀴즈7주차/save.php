<?php
    ini_set("display_errors",'0');
    $name = $_GET['name'];
    $include = $_GET['include'];
    $d = true;
    $d2 = true;
    $arr = file("data.txt");
    foreach($arr as $line) {
        $str = iconv("EUC-KR","UTF-8",$line);
        if(strpos($str,$name) !== false) {
            $d = false;     
        }
        if(strpos($str,$include) !== false) {
            $d2 = false;
        }
    }
    if($d == false && $d2 == false) {
        echo "저장되지 않았습니다.\n이전에 같은 파일의 이름으로 저장된 정보가 있습니다.";
    }
    else {
        $myfile = fopen("data.txt", "a+") or die("Unable to open file!");
        fwrite($myfile, $name);
        fwrite($myfile,"\n");
        fwrite($myfile, $include);
        fwrite($myfile,"\n");
        fclose($myfile);
        echo "저장되었습니다.";
    }
?>