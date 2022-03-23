<?php
    $numbers = ['','Rock','Scissor','Paper'];
    if (isset($_GET['uchoice']))
    {
        $uchoice = $_GET['uchoice'];
        $cchoice=rand(1,3);
        echo 'You chose '.$numbers[$uchoice];
        echo' & Computer chose '.$numbers[$cchoice].'. ';
        if($uchoice == 1 && $cchoice == 2)
            echo 'You Won.';
        else if($uchoice == 1 && $cchoice == 3)
            echo 'Computer Won.';
        else if($uchoice == 2 && $cchoice == 1)
            echo 'Computer Won.';
        else if($uchoice == 2 && $cchoice == 3)
            echo 'You Won.';
        else if($uchoice == 3 && $cchoice == 1)
            echo 'You Won.';
        else if($uchoice == 3 && $cchoice == 2)
            echo 'Computer Won.';
        else
            echo 'Its a tie. Please play again.';
    }
?>

<!DOCTYPE html>
<html>
<head>
    <title>RSP</title>
</head>
<body>
    <br>
    <a href="rsp.php?uchoice=1">Rock</a><br>
    <a href="rsp.php?uchoice=2">Scissor</a><br>
    <a href="rsp.php?uchoice=3">Paper</a><br>
    <a href="rsp.php">Play Again</a>
</body>
</html>