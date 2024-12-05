-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 04, 2024 at 12:02 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `ashesii`
--

-- --------------------------------------------------------

--
-- Table structure for table `administrators`
--

CREATE TABLE `administrators` (
  `AdminID` int(11) NOT NULL,
  `FullName` varchar(255) NOT NULL,
  `Email` varchar(100) NOT NULL,
  `Password` varchar(255) NOT NULL,
  `UserID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `administrators`
--

INSERT INTO `administrators` (`AdminID`, `FullName`, `Email`, `Password`, `UserID`) VALUES
(0, 'John Doe', 'john.doe@admin.com', 'Admin123', 1);

-- --------------------------------------------------------

--
-- Table structure for table `attendance`
--

CREATE TABLE `attendance` (
  `AttendanceID` int(11) NOT NULL,
  `StudentID` int(11) DEFAULT NULL,
  `ClassDate` date DEFAULT NULL,
  `Status` enum('Present','Absent') DEFAULT NULL,
  `Present` tinyint(1) NOT NULL DEFAULT 1,
  `AttendanceDate` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `attendance`
--

INSERT INTO `attendance` (`AttendanceID`, `StudentID`, `ClassDate`, `Status`, `Present`, `AttendanceDate`) VALUES
(1, 1, '2024-11-01', 'Present', 1, '2024-11-01'),
(9, 3, '2024-11-03', 'Absent', 0, '2024-11-03'),
(10, 4, '2024-11-01', 'Present', 1, '2024-11-01');

-- --------------------------------------------------------

--
-- Table structure for table `courses`
--

CREATE TABLE `courses` (
  `CourseID` int(11) NOT NULL,
  `CourseName` varchar(255) NOT NULL,
  `Credits` int(11) NOT NULL,
  `Prerequisite` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `courses`
--

INSERT INTO `courses` (`CourseID`, `CourseName`, `Credits`, `Prerequisite`) VALUES
(0, 'Psychology', 3, 0),
(0, 'Psychology', 3, 0),
(0, 'Psychology', 3, 0);

-- --------------------------------------------------------

--
-- Table structure for table `faculties`
--

CREATE TABLE `faculties` (
  `FacultyID` int(11) NOT NULL,
  `FirstName` varchar(100) NOT NULL,
  `LastName` varchar(100) NOT NULL,
  `Department` varchar(100) NOT NULL,
  `DateOfAppointment` date NOT NULL,
  `UserID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `faculties`
--

INSERT INTO `faculties` (`FacultyID`, `FirstName`, `LastName`, `Department`, `DateOfAppointment`, `UserID`) VALUES
(1, 'Jane', 'Smith', 'Mathematics', '2024-04-02', 11),
(50, 'Sarah', 'Hassan', 'Computer Science', '2024-12-03', NULL),
(56, 'Nana', 'Kwabena', 'Physics', '2024-12-24', NULL),
(67, 'Ken', 'Walibora', 'Computer Science', '2024-12-13', NULL),
(90, 'Keneth', 'Peter', 'Physics', '2024-12-11', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `grades`
--

CREATE TABLE `grades` (
  `GradeID` int(11) NOT NULL,
  `StudentID` int(11) DEFAULT NULL,
  `CourseID` int(11) DEFAULT NULL,
  `Grade` varchar(2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `grades`
--

INSERT INTO `grades` (`GradeID`, `StudentID`, `CourseID`, `Grade`) VALUES
(0, 2, 1, 'A'),
(0, 5, 4, 'G'),
(0, 1, 1, 'A'),
(0, 10, 0, 'A'),
(0, 1, 0, 'A');

-- --------------------------------------------------------

--
-- Table structure for table `payments`
--

CREATE TABLE `payments` (
  `PaymentID` int(11) NOT NULL,
  `StudentID` int(11) DEFAULT NULL,
  `Amount` decimal(10,2) DEFAULT NULL,
  `PaymentDate` datetime DEFAULT current_timestamp(),
  `PaymentMethod` varchar(50) DEFAULT NULL,
  `Status` varchar(50) DEFAULT NULL,
  `Notes` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `payments`
--

INSERT INTO `payments` (`PaymentID`, `StudentID`, `Amount`, `PaymentDate`, `PaymentMethod`, `Status`, `Notes`) VALUES
(1, 2, 10000.00, '2024-12-02 15:07:43', 'Cash', 'Pending', 'I will pay the rest later'),
(3, 6, 5000.00, '2024-12-02 20:10:30', 'Credit Card', 'Refunded', 'we gave back the extra money'),
(4, 10, 10000.00, '2024-12-18 21:16:01', 'Cheque', 'Paid', 'Done'),
(5, 1, 10000.00, '2024-12-18 21:26:51', 'Cash', 'Paid', 'Yaay'),
(6, 1, 20000.00, '2024-12-02 22:57:02', 'Bank Transfer', 'Pending', 'None');

-- --------------------------------------------------------

--
-- Table structure for table `profilemanagement`
--

CREATE TABLE `profilemanagement` (
  `UserID` int(11) NOT NULL,
  `FirstName` varchar(50) DEFAULT NULL,
  `LastName` varchar(50) DEFAULT NULL,
  `Email` varchar(100) DEFAULT NULL,
  `Password` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `reports`
--

CREATE TABLE `reports` (
  `ReportID` int(11) NOT NULL,
  `ReportType` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `schedule`
--

CREATE TABLE `schedule` (
  `ScheduleID` int(11) NOT NULL,
  `StudentID` int(11) DEFAULT NULL,
  `CourseName` varchar(255) DEFAULT NULL,
  `Day` varchar(50) DEFAULT NULL,
  `Time` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `schedule`
--

INSERT INTO `schedule` (`ScheduleID`, `StudentID`, `CourseName`, `Day`, `Time`) VALUES
(1, 1, 'Mathematics', 'SUNDAY', '5:00 AM - 10:00 AM');

-- --------------------------------------------------------

--
-- Table structure for table `students`
--

CREATE TABLE `students` (
  `StudentID` int(11) NOT NULL,
  `FirstName` varchar(100) NOT NULL,
  `LastName` varchar(100) NOT NULL,
  `Major` varchar(100) DEFAULT NULL,
  `EnrollmentDate` date NOT NULL,
  `UserID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `students`
--

INSERT INTO `students` (`StudentID`, `FirstName`, `LastName`, `Major`, `EnrollmentDate`, `UserID`) VALUES
(1, 'Yaa', 'Asantewaa', 'Computer Science', '2022-09-01', 21),
(2, 'Student Two', 'Student', 'Mathematics', '2022-09-02', 22),
(3, 'Student Three', 'Student', 'Physics', '2022-09-03', 23),
(4, 'Student Four', 'Student', 'Chemistry', '2022-09-04', 24),
(6, 'Student Six', 'Student', 'Literature', '2022-09-06', 26),
(7, 'Student Seven', 'Student', 'History', '2022-09-07', 27),
(10, 'Purity ', 'Moraa', 'Political Science', '2022-09-10', 30);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `UserID` int(11) NOT NULL,
  `FirstName` varchar(100) NOT NULL,
  `LastName` varchar(100) NOT NULL,
  `Email` varchar(100) NOT NULL,
  `Password` varchar(255) NOT NULL,
  `Role` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`UserID`, `FirstName`, `LastName`, `Email`, `Password`, `Role`) VALUES
(1, 'John', 'Doe', 'John.doe@admin.com', 'Admin123', 1),
(11, 'Jane', 'Smith', 'jane.smith@faculty.com', 'faculty123', 2),
(21, 'Yaa', 'Asantewaa', 'yaa.asantewaa@student.com', 'asantawaa123', 3),
(30, 'Purity', 'Moraa', 'purity.moraa@student.com', 'moraa123', 3);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `attendance`
--
ALTER TABLE `attendance`
  ADD PRIMARY KEY (`AttendanceID`),
  ADD KEY `StudentID` (`StudentID`);

--
-- Indexes for table `faculties`
--
ALTER TABLE `faculties`
  ADD PRIMARY KEY (`FacultyID`);

--
-- Indexes for table `payments`
--
ALTER TABLE `payments`
  ADD PRIMARY KEY (`PaymentID`),
  ADD KEY `StudentID` (`StudentID`);

--
-- Indexes for table `schedule`
--
ALTER TABLE `schedule`
  ADD PRIMARY KEY (`ScheduleID`),
  ADD KEY `StudentID` (`StudentID`);

--
-- Indexes for table `students`
--
ALTER TABLE `students`
  ADD PRIMARY KEY (`StudentID`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`UserID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `attendance`
--
ALTER TABLE `attendance`
  MODIFY `AttendanceID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `faculties`
--
ALTER TABLE `faculties`
  MODIFY `FacultyID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=91;

--
-- AUTO_INCREMENT for table `payments`
--
ALTER TABLE `payments`
  MODIFY `PaymentID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `schedule`
--
ALTER TABLE `schedule`
  MODIFY `ScheduleID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `students`
--
ALTER TABLE `students`
  MODIFY `StudentID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `UserID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=31;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `attendance`
--
ALTER TABLE `attendance`
  ADD CONSTRAINT `attendance_ibfk_1` FOREIGN KEY (`StudentID`) REFERENCES `students` (`StudentID`);

--
-- Constraints for table `payments`
--
ALTER TABLE `payments`
  ADD CONSTRAINT `payments_ibfk_1` FOREIGN KEY (`StudentID`) REFERENCES `students` (`StudentID`);

--
-- Constraints for table `schedule`
--
ALTER TABLE `schedule`
  ADD CONSTRAINT `schedule_ibfk_1` FOREIGN KEY (`StudentID`) REFERENCES `students` (`StudentID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
