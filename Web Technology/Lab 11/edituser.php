<?php
    if(!isset($_GET['id']))
    {
        header('Location:user.php');
    }
    // $pdo = new PDO('mysql:dbname=sagarmathacsit; host=localhost', 'root', '');
    require 'db.php';
    
    $id = $_GET['id'];
    $stmt = $pdo -> query("SELECT * FROM table_user WHERE id = '$id'");
    $user = $stmt -> fetch();

    if(isset($_POST['update']))
    {
        extract($_POST); //make variables of array index
        $pdo ->query ("UPDATE table_user SET name ='$name', address='$address',
                                email = '$email', birthdate='$birthdate' WHERE id = '$id'");
        header('Location:user.php?msg=User Updated');
    }
?>

<h3>Edit User Detail</h3>
<form method = "POST" action = "">
    <input type="hidden" name="id" value="<?php echo $user['id'];?>">
    Name : <input type = "text" name = "name" value="<?php echo $user['name'];?>"><br><br>
    Address : <input type = "text" name = "address" value="<?php echo $user['address'];?>"><br><br>
    Email : <input type = "email" name = "email" value="<?php echo $user['email'];?>"><br><br>
    Birth Date : <input type = "date" name = "birthdate" value="<?php echo $user['birthdate'];?>"><br><br>
    <input type  = "submit" name = "update" value = "Update">
</form>