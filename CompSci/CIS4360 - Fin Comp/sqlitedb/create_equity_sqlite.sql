CREATE TABLE [EquityDailyPrice](
	[Ticker] [nvarchar](50),
	[AsOfDate] [date],
	[Open] [float] NOT NULL,
	[High] [float] NOT NULL,
	[Low] [float] NOT NULL,
	[Close] [float] NOT NULL,
	[Volume] [float] NOT NULL,
	[TurnOver] [float] NOT NULL,
	[Dividend] [float] NOT NULL,
	primary key (Ticker, AsOfDate)
 );



CREATE TABLE [EquityIntradayPrice](
	[Ticker] [nvarchar](50) NOT NULL,
	[AsOfDate] [date] NOT NULL,
	[DateIndex] [int] NOT NULL,
	[AsOfTime] [datetime] NOT NULL,
	[Open] [float] NOT NULL,
	[High] [float] NOT NULL,
	[Low] [float] NOT NULL,
	[Close] [float] NOT NULL,
	[Volume] [float] NOT NULL,
	primary key (Ticker, AsOfTime)
);
