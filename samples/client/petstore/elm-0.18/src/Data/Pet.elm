{-
   OpenAPI Petstore
   This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.

   OpenAPI spec version: 1.0.0

   NOTE: This file is auto generated by the openapi-generator.
   https://github.com/openapitools/openapi-generator.git
   Do not edit this file manually.
-}


module Data.Pet exposing (Pet, Status(..), decoder, encode)

import Data.Category as Category exposing (Category)
import Data.Tag as Tag exposing (Tag)
import Dict exposing (Dict)
import Json.Decode as Decode exposing (Decoder)
import Json.Decode.Pipeline exposing (decode, optional, required)
import Json.Encode as Encode


{-| A pet for sale in the pet store
-}
type alias Pet =
    { id : Maybe Int
    , category : Maybe Category
    , name : String
    , photoUrls : List String
    , tags : Maybe (List Tag)
    , status : Maybe Status
    }


type Status
    = Available
    | Pending
    | Sold


decoder : Decoder Pet
decoder =
    decode Pet
        |> optional "id" (Decode.nullable Decode.int) Nothing
        |> optional "category" (Decode.nullable Category.decoder) Nothing
        |> required "name" Decode.string
        |> required "photoUrls" (Decode.list Decode.string)
        |> optional "tags" (Decode.nullable (Decode.list Tag.decoder)) Nothing
        |> optional "status" (Decode.nullable statusDecoder) Nothing


encode : Pet -> Encode.Value
encode model =
    Encode.object
        [ ( "id", Maybe.withDefault Encode.null (Maybe.map Encode.int model.id) )
        , ( "category", Maybe.withDefault Encode.null (Maybe.map Category.encode model.category) )
        , ( "name", Encode.string model.name )
        , ( "photoUrls", (Encode.list << List.map Encode.string) model.photoUrls )
        , ( "tags", Maybe.withDefault Encode.null (Maybe.map (Encode.list << List.map Tag.encode) model.tags) )
        , ( "status", Maybe.withDefault Encode.null (Maybe.map encodeStatus model.status) )
        ]


statusDecoder : Decoder Status
statusDecoder =
    Decode.string
        |> Decode.andThen
            (\str ->
                case str of
                    "available" ->
                        Decode.succeed Available

                    "pending" ->
                        Decode.succeed Pending

                    "sold" ->
                        Decode.succeed Sold

                    other ->
                        Decode.fail <| "Unknown type: " ++ other
            )


encodeStatus : Status -> Encode.Value
encodeStatus model =
    case model of
        Available ->
            Encode.string "available"

        Pending ->
            Encode.string "pending"

        Sold ->
            Encode.string "sold"
