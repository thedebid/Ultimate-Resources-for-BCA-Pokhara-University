<?php
$servername = "localhost";
$username = "root";
$password = "exam";
$dbname = "STD_DB";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

// Create table
$sql = "CREATE TABLE Std_info (
stdId INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
stdName VARCHAR(30) NOT NULL,
stdaddress VARCHAR(30) NOT NULL,
faculty VARCHAR(50),
semester VARCHAR(50),
joinDate TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
fee INT,
)";

if (mysqli_query($conn, $sql)) {
    echo "Table StdInfo created successfully";
  } else {
    echo "Error creating table: " . mysqli_error($conn);
  }


//insert Data
$sql = "INSERT INTO Std_info (stdName, stdaddress, faculty,semester,joinDate,fee)
VALUES ('Hari Bhandari', 'Pokhara', 'BCA','6th','2018',500000)";

if (mysqli_query($conn, $sql)) {
    echo "New student record created successfully";
  } else {
    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
  }


//select data
$sql = "SELECT * FROM Std_info";
$result = mysqli_query($conn, $sql);
if (mysqli_num_rows($result) > 0) {
  // output data of each row
  while($row = mysqli_fetch_assoc($result)) {
    echo "id: " . $row["stdId"]. " - Name: " . $row["stdName"]. " - Address: " . $row["stdaddress"]. " - Faculty: " . $row["faculty"]. " - Semester: " . $row["semester"]. " - Join Date: " . $row["joinDate"].  " - Fee: " . $row["fee"].  " <br>";
  }
} else {
  echo "0 student records found";
}



//update data
$sql = "UPDATE Std_info SET stdName='Suresh Baral', stdaddress='gaindakot',faculty='BBA' WHERE stdId=1";

if (mysqli_query($conn, $sql)) {
  echo "Student record updated successfully";
} else {
  echo "Error updating record: " . mysqli_error($conn);
}


// delete data
$sql = "DELETE FROM Std_info WHERE stdId=2";

if (mysqli_query($conn, $sql)) {
  echo "Student  record deleted successfully";
} else {
  echo "Error deleting record: " . mysqli_error($conn);
}

mysqli_close($conn);

?>