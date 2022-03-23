<?php
    session_start();
    if (!isset($_SESSION['suserid']))
    {
        header('Location:login.php');
    }

    // $pdo = new PDO('mysql:dbname=sagarmathacsit; host=localhost', 'root', '');
    require 'db.php';
    
    if(isset($_POST['add']))
    {
        // $name = $_POST['name'];
        // $address = $_POST['address'];
        // $email = $_POST['email'];
        // $birthdate = $_POST['birthdate'];
        extract ($_POST); //make variables of array index
        $r = $pdo -> query ("INSERT INTO table_user(id,name,address,email,birthdate)
                                            VALUES('','$name','$address','$email','$birthdate')");
        // if($r == true) echo 'User detail inserted';
        // else echo 'Not inserted';
        echo 'Inserted';
    }

    if (isset($_GET['msg']))
    {
        echo $_GET['msg'];
    }

    if (isset($_GET['id']))
    {
        $id = $_GET['id'];
        $pdo -> query ("DELETE FROM table_user WHERE id='$id'");
        echo 'User Deleted';
    }    
?>


<h3>Enter User Detail</h3>
<form method = "POST" action = "">
    Name : <input type = "text" name = "name"><br><br>
    Address : <input type = "text" name = "address"><br><br>
    Email : <input type = "email" name = "email"><br><br>
    Birth Date : <input type = "date" name = "birthdate"><br><br>
    <input type  = "submit" name = "add" value = "Add">
</form>

<h3>UserList</h3>
<table border="1">
    <tr>
        <th>Name</th>
        <th>Address</th>
        <th>Email</th>
        <th>Birth Date</th>
        <th>Action</th>
    </tr>
    <?php
        $userList = $pdo -> query ("SELECT * FROM table_user");
        foreach ($userList as $user)
        {
    ?>
    <tr>
        <td><?php echo $user['name']?></td>
        <td><?php echo $user['address']?></td>
        <td><?php echo $user['email']?></td>
        <td><?php echo $user['birthdate']?></td>
        <td>
            <a href="edituser.php?id=<?php echo $user['id'];?>">Edit</a>
            <a href="user.php?id=<?php echo $user['id'];?>">Delete</a>
        </td>
    </tr>
    <?php 
        }
    ?>
</table>

<br><br>
<a href="index.php"><input type ="submit" value="Back"></a>