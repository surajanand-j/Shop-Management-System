-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 24, 2019 at 11:47 AM
-- Server version: 10.4.6-MariaDB
-- PHP Version: 7.3.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `ds`
--

-- --------------------------------------------------------

--
-- Table structure for table `bill`
--

CREATE TABLE `bill` (
  `num` int(11) NOT NULL,
  `id` int(11) NOT NULL,
  `consumer` varchar(255) NOT NULL,
  `medicine` varchar(255) NOT NULL,
  `quantity` int(11) NOT NULL,
  `rate` int(11) NOT NULL,
  `total` int(11) NOT NULL,
  `date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `bill`
--

INSERT INTO `bill` (`num`, `id`, `consumer`, `medicine`, `quantity`, `rate`, `total`, `date`) VALUES
(1, 90, 'shubham', 'comiflame', 10, 1000, 10000, '2019-10-23'),
(2, 3, 'shubham', 'paractemol', 7, 120, 840, '2019-11-23'),
(3, 10, 'pulkit', 'comiflame', 12, 1000, 12000, '2019-11-23'),
(4, 90, 'shubham', 'comiflame', 4, 1000, 4000, '2019-11-23'),
(5, 90, 'shubham', 'comiflame', 4, 1000, 4000, '2019-11-24');

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `id` int(11) NOT NULL,
  `name` varchar(15) NOT NULL,
  `number` bigint(20) NOT NULL,
  `city` varchar(15) NOT NULL,
  `email` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`id`, `name`, `number`, `city`, `email`) VALUES
(101, 'shubham', 7300857619, 'delhi', 'gypta@gmail.com'),
(102, 'pulkit', 9137828172, 'Pune', 'puls@gmail.com');

-- --------------------------------------------------------

--
-- Table structure for table `medicial`
--

CREATE TABLE `medicial` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `rack` int(11) NOT NULL,
  `cabnit` varchar(255) NOT NULL,
  `company` varchar(255) NOT NULL,
  `supplier` varchar(255) NOT NULL,
  `unit_cost` int(11) NOT NULL,
  `sale_cost` int(11) NOT NULL,
  `quantity` int(11) NOT NULL,
  `men_date` date NOT NULL,
  `exp_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `medicial`
--

INSERT INTO `medicial` (`id`, `name`, `rack`, `cabnit`, `company`, `supplier`, `unit_cost`, `sale_cost`, `quantity`, `men_date`, `exp_date`) VALUES
(101, 'comiflame', 90, '7118', 'shus', 'shubham', 90, 1000, 8, '2019-10-24', '2021-10-10'),
(102, 'paractemol', 90, '7619', 'shus', 'pulkit', 100, 120, 18, '2019-08-20', '2022-10-12');

-- --------------------------------------------------------

--
-- Table structure for table `profitreport`
--

CREATE TABLE `profitreport` (
  `num` int(11) NOT NULL,
  `id` int(11) NOT NULL,
  `medicine` varchar(255) NOT NULL,
  `quantity` int(11) NOT NULL,
  `unit` int(11) NOT NULL,
  `rate` int(11) NOT NULL,
  `profit` int(11) NOT NULL,
  `date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `profitreport`
--

INSERT INTO `profitreport` (`num`, `id`, `medicine`, `quantity`, `unit`, `rate`, `profit`, `date`) VALUES
(1, 101, 'combiflame', 10, 90, 1000, 9100, '2019-10-23'),
(2, 102, 'paratecamol', 7, 100, 120, 140, '2019-11-23'),
(3, 101, 'comiflame', 12, 90, 1000, 10920, '2019-11-23'),
(4, 101, 'comiflame', 4, 90, 1000, 3640, '2019-11-23'),
(5, 101, 'comiflame', 4, 90, 1000, 3640, '2019-11-24');

-- --------------------------------------------------------

--
-- Table structure for table `purchase`
--

CREATE TABLE `purchase` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `supplier` varchar(255) NOT NULL,
  `quantity` int(11) NOT NULL,
  `rate` float NOT NULL,
  `total` float NOT NULL,
  `date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `purchase`
--

INSERT INTO `purchase` (`id`, `name`, `supplier`, `quantity`, `rate`, `total`, `date`) VALUES
(101, 'comiflame', 'shubham', 10, 90, 900, '2019-10-22'),
(102, 'paractemol', 'pulkit', 15, 100, 1500, '2019-10-22'),
(101, 'comiflame', 'shubham', 10, 90, 1710, '2019-10-23'),
(102, 'paractemol', 'pulkit', 10, 100, 1800, '2019-10-23'),
(101, 'comiflame', 'shubham', 2, 90, 1890, '2019-10-23'),
(101, 'comiflame', 'shubham', 3, 90, 2160, '2019-10-23'),
(101, 'comiflame', 'shubham', 4, 90, 1080, '2019-10-24');

-- --------------------------------------------------------

--
-- Table structure for table `salereport`
--

CREATE TABLE `salereport` (
  `num` int(11) NOT NULL,
  `id` int(11) NOT NULL,
  `medicine` varchar(255) NOT NULL,
  `consumer` varchar(255) NOT NULL,
  `quantity` int(11) NOT NULL,
  `rate` int(11) NOT NULL,
  `total` int(11) NOT NULL,
  `date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `salereport`
--

INSERT INTO `salereport` (`num`, `id`, `medicine`, `consumer`, `quantity`, `rate`, `total`, `date`) VALUES
(1, 101, 'comiflame', 'shubham', 10, 1000, 10000, '2019-10-23'),
(2, 102, 'paractemol', 'shubham', 7, 120, 840, '2019-11-23'),
(3, 101, 'comiflame', 'pulkit', 12, 1000, 12000, '2019-11-23'),
(4, 101, 'comiflame', 'shubham', 4, 1000, 4000, '2019-11-23'),
(5, 101, 'comiflame', 'shubham', 4, 1000, 4000, '2019-11-24');

-- --------------------------------------------------------

--
-- Table structure for table `supplier`
--

CREATE TABLE `supplier` (
  `id` int(11) NOT NULL,
  `name` varchar(15) NOT NULL,
  `number` bigint(20) NOT NULL,
  `city` varchar(15) NOT NULL,
  `email` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `supplier`
--

INSERT INTO `supplier` (`id`, `name`, `number`, `city`, `email`) VALUES
(101, 'shubham', 7300857619, 'noida', 'gupta1@gmail.com'),
(102, 'pulkit', 982107819, 'delhi', 'pulkit@gmail.com');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `bill`
--
ALTER TABLE `bill`
  ADD PRIMARY KEY (`num`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `medicial`
--
ALTER TABLE `medicial`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `profitreport`
--
ALTER TABLE `profitreport`
  ADD PRIMARY KEY (`num`);

--
-- Indexes for table `purchase`
--
ALTER TABLE `purchase`
  ADD KEY `id` (`id`);

--
-- Indexes for table `salereport`
--
ALTER TABLE `salereport`
  ADD PRIMARY KEY (`num`);

--
-- Indexes for table `supplier`
--
ALTER TABLE `supplier`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `bill`
--
ALTER TABLE `bill`
  MODIFY `num` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `customer`
--
ALTER TABLE `customer`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=103;

--
-- AUTO_INCREMENT for table `profitreport`
--
ALTER TABLE `profitreport`
  MODIFY `num` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `salereport`
--
ALTER TABLE `salereport`
  MODIFY `num` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `supplier`
--
ALTER TABLE `supplier`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=103;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
