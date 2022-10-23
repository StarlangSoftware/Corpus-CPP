//
// Created by Olcay Taner Yıldız on 11.01.2019.
//

#include "Paragraph.h"

/**
 * A constructor of {@link Paragraph} class which creates an {@link vector} sentences.
 */
Paragraph::Paragraph() = default;

/**
 * The addSentence method adds given sentence to sentences {@link vector}.
 *
 * @param s Sentence type input to add sentences.
 */
void Paragraph::addSentence(Sentence* s) {
    sentences.emplace_back(s);
}

/**
 * The sentenceCount method finds the size of the {@link vector} sentences.
 *
 * @return the size of the {@link vector} sentences.
 */
int Paragraph::sentenceCount() const{
    return (int) sentences.size();
}

/**
 * The getSentence method finds the sentence from sentences {@link ArrayList} at given index.
 *
 * @param index used to get a sentence.
 * @return sentence at given index.
 */
Sentence* Paragraph::getSentence(unsigned long index) const{
    return sentences.at(index);
}
