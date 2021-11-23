const express = require("express");
const mongoose = require("mongoose");
const router = express.Router();

// Creating the schema for a book document
const bookSchema = new mongoose.Schema({
	bookId: { type: String, required: true },
	bookName: { type: String, required: true },
	publisher: { type: String, required: true },
	date: { type: String, required: true },
	authors: [String],
});

// Creating a model from the schema
const Book = mongoose.model("Book", bookSchema);

// Route Handling

// READ

router.get("/", async (req, res, next) => {
	let books = [];

	try {
		books = await Book.find({});
	} catch (err) {
		console.log(err);
	}

	res.send({ books });
});

// CREATE

router.post("/", async (req, res, next) => {
	const body = req.body;

	let newBook = new Book({
		bookId: body.bookId,
		bookName: body.bookName,
		publisher: body.publisher,
		date: body.date,
		authors: body.authors,
	});

	try {
		await newBook.save();
	} catch (err) {
		console.log(err);
	}

	res.send({ bookDetails: newBook });
});

//DELETE

router.delete("/:id", async (req, res, next) => {
	const bookId = req.params.id;
	const deletedBook = await Book.findOneAndDelete(
		{ bookId: bookId },
		(err, docs) => {
			if (err) {
				console.log(err);
			} else {
				res.send({ deletedBook: docs });
			}
		}
	);
});

// UPDATE

router.put("/:id", async (req, res, next) => {
	let bookId = req.params.id;
	const body = req.body;

	let newBook = {
		bookId: body.bookId,
		bookName: body.bookName,
		publisher: body.publisher,
		date: body.date,
		authors: body.authors,
	};

	Book.findOneAndUpdate(
		{ bookId: bookId },
		newBook,
		{ new: true },
		(err, docs) => {
			if (err) {
				console.log(err);
			} else {
				res.send(docs);
			}
		}
	);
});

//Export the routes in the router object

module.exports = router;
