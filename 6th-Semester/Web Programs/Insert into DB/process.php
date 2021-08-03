<?php
$email = $_POST['email'];
$pass = $_POST['pass'];
$cpass = $_POST['cpass'];
if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
    echo "Email Invalid";
    return;
}
if ($pass != $cpass) {
    echo "Confirm Password Didnot Matched";
    return;
}
$conxn = mysqli_connect('localhost', 'root', '', ' demo');
$sql = "INSERT into user_info (email, password) VALUES ('$email' ,'$pass')";
$res = mysqli_query($conxn, $sql) or die(mysqli_error($conxn));
$affRows = mysqli_affected_rows($conxn);
if ($affRows > 0) {
    echo "User Record Inserted";
} else {
    echo "User Record Not Inserted";
}
mysqli_close($conxn);
?>