-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Apr 22, 2025 at 01:16 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bu_e-registration_system`
--

-- --------------------------------------------------------

--
-- Table structure for table `bucet`
--

CREATE TABLE `bucet` (
  `bucet_id` int(11) NOT NULL,
  `year_graduated` int(11) NOT NULL,
  `high_school` varchar(150) NOT NULL,
  `composite_rating` decimal(5,2) NOT NULL,
  `permit_number` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `bucet`
--

INSERT INTO `bucet` (`bucet_id`, `year_graduated`, `high_school`, `composite_rating`, `permit_number`) VALUES
(1, 2022, 'Divine Word College of Legazpi', 99.90, '1234-5678-54321');

-- --------------------------------------------------------

--
-- Table structure for table `class`
--

CREATE TABLE `class` (
  `class_id` int(11) NOT NULL,
  `room_id` int(11) NOT NULL,
  `class_code` varchar(20) NOT NULL,
  `section_id` int(11) NOT NULL,
  `personnel_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `class`
--

INSERT INTO `class` (`class_id`, `room_id`, `class_code`, `section_id`, `personnel_id`) VALUES
(1, 1, 'CS105', 1, 1);

-- --------------------------------------------------------

--
-- Table structure for table `college`
--

CREATE TABLE `college` (
  `college_id` int(11) NOT NULL,
  `college_code` varchar(20) NOT NULL,
  `name` varchar(100) NOT NULL,
  `address` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `college`
--

INSERT INTO `college` (`college_id`, `college_code`, `name`, `address`) VALUES
(1, 'CS', 'College of Sciences', 'Ems, Legazpi, Philippines'),
(2, 'CE', 'College of Education', 'Rizal Street, Daraga, Philippines'),
(3, 'CBEM', 'College of Business, Economics, and Management', 'Bicol University, Daraga Campus, Daraga, Albay, Daraga, Philippines'),
(4, 'CN', 'College of Nursing', 'Ems, Legazpi, Philippines'),
(5, 'CSSP', 'College of Social Sciences and Philosophy', 'Bicol University, Daraga Campus, Daraga, Albay, Daraga, Philippines');

-- --------------------------------------------------------

--
-- Table structure for table `course`
--

CREATE TABLE `course` (
  `course_id` int(11) NOT NULL,
  `course_code` varchar(20) NOT NULL,
  `name` varchar(100) NOT NULL,
  `description` varchar(500) DEFAULT NULL,
  `total_units` decimal(3,1) NOT NULL,
  `college_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `course`
--

INSERT INTO `course` (`course_id`, `course_code`, `name`, `description`, `total_units`, `college_id`) VALUES
(1, 'CS105', 'Information Management', 'Learning about Databases and Database Design', 3.0, 1);

-- --------------------------------------------------------

--
-- Table structure for table `department`
--

CREATE TABLE `department` (
  `department_id` int(11) NOT NULL,
  `college_id` int(11) NOT NULL,
  `department_code` varchar(20) NOT NULL,
  `name` varchar(100) NOT NULL,
  `acronym` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `department`
--

INSERT INTO `department` (`department_id`, `college_id`, `department_code`, `name`, `acronym`) VALUES
(1, 1, 'CS', 'Computer Science', 'CS');

-- --------------------------------------------------------

--
-- Table structure for table `dropout_student`
--

CREATE TABLE `dropout_student` (
  `d_student_id` int(11) NOT NULL,
  `date_dropped` date NOT NULL,
  `remarks` varchar(2000) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `grade`
--

CREATE TABLE `grade` (
  `grade_id` int(11) NOT NULL,
  `class_id` int(11) NOT NULL,
  `student_id` int(11) NOT NULL,
  `midterm` decimal(5,2) DEFAULT NULL CHECK (`midterm` between 0 and 100),
  `finals` decimal(5,2) DEFAULT NULL CHECK (`finals` between 0 and 100)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `grade`
--

INSERT INTO `grade` (`grade_id`, `class_id`, `student_id`, `midterm`, `finals`) VALUES
(1, 1, 1, 99.90, 99.90);

-- --------------------------------------------------------

--
-- Table structure for table `personnel`
--

CREATE TABLE `personnel` (
  `personnel_id` int(11) NOT NULL,
  `first_name` varchar(50) NOT NULL,
  `last_name` varchar(50) NOT NULL,
  `is_active` tinyint(1) NOT NULL DEFAULT 1,
  `department_id` int(11) NOT NULL,
  `personnel_position_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `personnel`
--

INSERT INTO `personnel` (`personnel_id`, `first_name`, `last_name`, `is_active`, `department_id`, `personnel_position_id`) VALUES
(1, 'Juan', 'Dila Cruz', 1, 1, 1);

-- --------------------------------------------------------

--
-- Table structure for table `personnel_position`
--

CREATE TABLE `personnel_position` (
  `personnel_position_id` int(11) NOT NULL,
  `name` varchar(50) NOT NULL,
  `description` varchar(200) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `personnel_position`
--

INSERT INTO `personnel_position` (`personnel_position_id`, `name`, `description`) VALUES
(1, 'Assistant Professor', 'Entry-level faculty position');

-- --------------------------------------------------------

--
-- Table structure for table `registration`
--

CREATE TABLE `registration` (
  `registration_id` int(11) NOT NULL,
  `college_year` tinyint(4) NOT NULL CHECK (`college_year` between 1 and 5),
  `create_at` date NOT NULL,
  `personnel_id` int(11) NOT NULL,
  `student_id` int(11) NOT NULL,
  `college_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `registration`
--

INSERT INTO `registration` (`registration_id`, `college_year`, `create_at`, `personnel_id`, `student_id`, `college_id`) VALUES
(1, 2, '2023-06-15', 1, 1, 1);

-- --------------------------------------------------------

--
-- Table structure for table `room`
--

CREATE TABLE `room` (
  `room_id` int(11) NOT NULL,
  `room_code` varchar(20) NOT NULL,
  `building` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `room`
--

INSERT INTO `room` (`room_id`, `room_code`, `building`) VALUES
(1, 'B2101', 'College of Science Building 2');

-- --------------------------------------------------------

--
-- Table structure for table `scholarship_student`
--

CREATE TABLE `scholarship_student` (
  `s_student_id` int(11) NOT NULL,
  `provider` varchar(100) NOT NULL,
  `is_active` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `scholarship_student`
--

INSERT INTO `scholarship_student` (`s_student_id`, `provider`, `is_active`) VALUES
(1, 'DOST', 1);

-- --------------------------------------------------------

--
-- Table structure for table `section`
--

CREATE TABLE `section` (
  `section_id` int(11) NOT NULL,
  `section_code` varchar(20) NOT NULL,
  `year` tinyint(4) NOT NULL CHECK (`year` between 1 and 5),
  `course_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `section`
--

INSERT INTO `section` (`section_id`, `section_code`, `year`, `course_id`) VALUES
(1, 'BSCS 2A', 2, 1);

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

CREATE TABLE `student` (
  `student_id` int(11) NOT NULL,
  `bucet_id` int(11) NOT NULL,
  `year_enrolled` int(11) NOT NULL,
  `first_name` varchar(50) NOT NULL,
  `last_name` varchar(50) NOT NULL,
  `sex` char(1) NOT NULL,
  `city` varchar(100) NOT NULL,
  `province` varchar(100) NOT NULL,
  `zip_code` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`student_id`, `bucet_id`, `year_enrolled`, `first_name`, `last_name`, `sex`, `city`, `province`, `zip_code`) VALUES
(1, 1, 2023, 'Michael Xavier', 'Canonizado', 'M', 'Pilar', 'Sorsogon', '4500');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `bucet`
--
ALTER TABLE `bucet`
  ADD PRIMARY KEY (`bucet_id`),
  ADD UNIQUE KEY `bucet_id` (`bucet_id`);

--
-- Indexes for table `class`
--
ALTER TABLE `class`
  ADD PRIMARY KEY (`class_id`),
  ADD UNIQUE KEY `class_id` (`class_id`),
  ADD KEY `room_id` (`room_id`),
  ADD KEY `section_id` (`section_id`),
  ADD KEY `personnel_id` (`personnel_id`);

--
-- Indexes for table `college`
--
ALTER TABLE `college`
  ADD PRIMARY KEY (`college_id`),
  ADD UNIQUE KEY `college_id` (`college_id`),
  ADD UNIQUE KEY `college_code` (`college_code`);

--
-- Indexes for table `course`
--
ALTER TABLE `course`
  ADD PRIMARY KEY (`course_id`),
  ADD UNIQUE KEY `course_id` (`course_id`),
  ADD UNIQUE KEY `course_code` (`course_code`),
  ADD KEY `college_id` (`college_id`);

--
-- Indexes for table `department`
--
ALTER TABLE `department`
  ADD PRIMARY KEY (`department_id`),
  ADD UNIQUE KEY `department_id` (`department_id`),
  ADD UNIQUE KEY `department_code` (`department_code`),
  ADD KEY `college_id` (`college_id`);

--
-- Indexes for table `dropout_student`
--
ALTER TABLE `dropout_student`
  ADD PRIMARY KEY (`d_student_id`);

--
-- Indexes for table `grade`
--
ALTER TABLE `grade`
  ADD PRIMARY KEY (`grade_id`),
  ADD UNIQUE KEY `grade_id` (`grade_id`),
  ADD KEY `class_id` (`class_id`),
  ADD KEY `student_id` (`student_id`);

--
-- Indexes for table `personnel`
--
ALTER TABLE `personnel`
  ADD PRIMARY KEY (`personnel_id`),
  ADD UNIQUE KEY `personnel_id` (`personnel_id`),
  ADD KEY `department_id` (`department_id`),
  ADD KEY `personnel_position_id` (`personnel_position_id`);

--
-- Indexes for table `personnel_position`
--
ALTER TABLE `personnel_position`
  ADD PRIMARY KEY (`personnel_position_id`),
  ADD UNIQUE KEY `position_id` (`personnel_position_id`);

--
-- Indexes for table `registration`
--
ALTER TABLE `registration`
  ADD PRIMARY KEY (`registration_id`),
  ADD UNIQUE KEY `registration_id` (`registration_id`),
  ADD KEY `personnel_id` (`personnel_id`),
  ADD KEY `student_id` (`student_id`),
  ADD KEY `college_id` (`college_id`);

--
-- Indexes for table `room`
--
ALTER TABLE `room`
  ADD PRIMARY KEY (`room_id`),
  ADD UNIQUE KEY `room_id` (`room_id`);

--
-- Indexes for table `scholarship_student`
--
ALTER TABLE `scholarship_student`
  ADD PRIMARY KEY (`s_student_id`),
  ADD UNIQUE KEY `s_student_id` (`s_student_id`);

--
-- Indexes for table `section`
--
ALTER TABLE `section`
  ADD PRIMARY KEY (`section_id`),
  ADD UNIQUE KEY `section_id` (`section_id`),
  ADD UNIQUE KEY `section_code` (`section_code`),
  ADD KEY `course_id` (`course_id`);

--
-- Indexes for table `student`
--
ALTER TABLE `student`
  ADD PRIMARY KEY (`student_id`),
  ADD UNIQUE KEY `student_id` (`student_id`),
  ADD KEY `bucet_id` (`bucet_id`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `class`
--
ALTER TABLE `class`
  ADD CONSTRAINT `class_ibfk_1` FOREIGN KEY (`room_id`) REFERENCES `room` (`room_id`),
  ADD CONSTRAINT `class_ibfk_2` FOREIGN KEY (`section_id`) REFERENCES `section` (`section_id`),
  ADD CONSTRAINT `class_ibfk_3` FOREIGN KEY (`personnel_id`) REFERENCES `personnel` (`personnel_id`);

--
-- Constraints for table `course`
--
ALTER TABLE `course`
  ADD CONSTRAINT `course_ibfk_1` FOREIGN KEY (`college_id`) REFERENCES `college` (`college_id`);

--
-- Constraints for table `department`
--
ALTER TABLE `department`
  ADD CONSTRAINT `department_ibfk_1` FOREIGN KEY (`college_id`) REFERENCES `college` (`college_id`);

--
-- Constraints for table `dropout_student`
--
ALTER TABLE `dropout_student`
  ADD CONSTRAINT `dropout_student_ibfk_1` FOREIGN KEY (`d_student_id`) REFERENCES `student` (`student_id`);

--
-- Constraints for table `grade`
--
ALTER TABLE `grade`
  ADD CONSTRAINT `grade_ibfk_1` FOREIGN KEY (`class_id`) REFERENCES `class` (`class_id`),
  ADD CONSTRAINT `grade_ibfk_2` FOREIGN KEY (`student_id`) REFERENCES `student` (`student_id`);

--
-- Constraints for table `personnel`
--
ALTER TABLE `personnel`
  ADD CONSTRAINT `personnel_ibfk_1` FOREIGN KEY (`department_id`) REFERENCES `department` (`department_id`),
  ADD CONSTRAINT `personnel_ibfk_2` FOREIGN KEY (`personnel_position_id`) REFERENCES `personnel_position` (`personnel_position_id`);

--
-- Constraints for table `registration`
--
ALTER TABLE `registration`
  ADD CONSTRAINT `registration_ibfk_1` FOREIGN KEY (`personnel_id`) REFERENCES `personnel` (`personnel_id`),
  ADD CONSTRAINT `registration_ibfk_2` FOREIGN KEY (`student_id`) REFERENCES `student` (`student_id`),
  ADD CONSTRAINT `registration_ibfk_3` FOREIGN KEY (`college_id`) REFERENCES `college` (`college_id`);

--
-- Constraints for table `scholarship_student`
--
ALTER TABLE `scholarship_student`
  ADD CONSTRAINT `scholarship_student_ibfk_1` FOREIGN KEY (`s_student_id`) REFERENCES `student` (`student_id`);

--
-- Constraints for table `section`
--
ALTER TABLE `section`
  ADD CONSTRAINT `section_ibfk_1` FOREIGN KEY (`course_id`) REFERENCES `course` (`course_id`);

--
-- Constraints for table `student`
--
ALTER TABLE `student`
  ADD CONSTRAINT `student_ibfk_1` FOREIGN KEY (`bucet_id`) REFERENCES `bucet` (`bucet_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
