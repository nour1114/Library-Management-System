from sqlalchemy import Column, Integer, String, Date, ForeignKey

from app.database import Base


class Loan(Base):
    __tablename__ = "loans"

    loan_id = Column(Integer, primary_key=True)

    book_id = Column(
        Integer,
        ForeignKey("books.book_id"),
        nullable=False
    )

    member_id = Column(
        Integer,
        ForeignKey("members.member_id"),
        nullable=False
    )

    borrow_date = Column(Date, nullable=False)
    return_date = Column(Date, nullable=False)

    status = Column(
        String(20),
        nullable=False,
        default="ACTIVE"
    )
