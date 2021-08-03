<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Factorial using recursion in PHP</title>
</head>

<body>
    <form method="post">
        Enter the Number:<br>
        <input type="number" name="number">
        <input type="submit" name="submit">
    </form>
</body>

</html>

<?php
if ($_POST) {
    function fact($num)
    {
        if ($num < 2) {
            return 1;
        } else {
            return ($num * fact($num - 1));
        }
    }
    $number = $_POST['number'];
    echo fact($number);
}
?>