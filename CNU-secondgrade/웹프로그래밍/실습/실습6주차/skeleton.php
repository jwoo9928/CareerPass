<!DOCTYPE html>
<html>
<body>
<h2>숫자 맞추기 게임</h2>
당신이 생각한 숫자를 컴퓨터가 맞추는 게임입니다.<br><br>

<?php
$userNumber = 9;                   // 당신이 생각하는 숫자를 넣으시오.
$j = 0;
$theVariable = [];

function numgame() {
    $num = rand(1,15);
    global $theVariable;
    while(isset($theVariable[$num])) {
        $num = rand(1,15);
    }
    $theVariable[$num] = 1;

    echo "The Number is ";
    echo $num;
    echo "!\n";
    global $userNumber;
    if($num == $userNumber){
        echo "correct!!!\n";
        return 1;
    } else {
        echo "fail\n";
        return 0;
    }
    
}
$i = 0;
while($i<15) {
    $flag = numgame();
    $i++;
    if($flag == 1) {
    break;
    }
}
echo "Game opportunity : ";
echo $i;
echo "times\n";
?>
</body>
</html>
