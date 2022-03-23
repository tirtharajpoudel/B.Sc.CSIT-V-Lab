<?php
    $records = [];
    $records[] = ['name'=>'Ramesh','extension'=>124];
    $records[] = ['name'=>'Anjali','extension'=>742];
    $records[] = ['name'=>'Kriti','extension'=>824];
    $records[] = ['name'=>'Sampad','extension'=>112];
    // echo'<pre>';
    // print_r($records);
?>

<table border="1">
    <tr>
        <td>Name</td>
        <td>Extension</td>
    </tr>
    <?php
        foreach($records as $row)
        {
            echo '<tr>';
            echo '<td>'.$row['name'].'</td>';
            echo '<td>'.$row['extension'].'</td>';
            echo '</tr>';
        }
    ?>
</table>
