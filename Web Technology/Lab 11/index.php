<?php
    session_start();
    if (!isset($_SESSION['suserid']))
    {
        header('Location:login.php');
    }
    if(isset($_GET['welcome']))
    {
        echo $_GET['welcome'];
    }
?>
<br>
<br>
<a href="user.php"><input type ="submit" value="User Panel"></a>&nbsp
<br><br>
<a href="logout.php"><input type ="submit" value="Log Out"></a>
