from sqlalchemy import Column, Integer, String

from app.database import Base


class Librarian(Base):
    __tablename__ = "librarians"

    librarian_id = Column(Integer, primary_key=True)
    name = Column(String(100), nullable=False)
