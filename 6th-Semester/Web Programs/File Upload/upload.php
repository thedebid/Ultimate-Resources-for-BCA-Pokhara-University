<?php
$name = $_FILES['myfile']['name'];
$tmp_name = $_FILES['tmp_name'];
if (move_uploaded_file($tmp_name, $name)) {
echo "file uploaded" ;
} else{
echo "file not uploaded" ;
}
?>